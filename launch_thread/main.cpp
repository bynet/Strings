#include <thread>
#include <iostream>
#include <random>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <ErrorMessage.hpp>
#include <mutex> 
//https://stackoverflow.com/questions/31897364/how-to-name-stdthread-on-mac-os-x-in-c11

class RandomNumber{
public:
    static int Generate(unsigned int lower_limit , unsigned int upper_limit ) {

        if( upper_limit <= lower_limit )
            throw std::invalid_argument( ErrorMessage() << "upperlimit " << upper_limit << " can not be smaller than lowerlimit " << lower_limit  ) ;
        std::srand(std::time(0));
        return  ( lower_limit + (std::rand() % (upper_limit - lower_limit ))); 
    }

};

class background_task{
    mutable std::string name ;
    mutable std::mutex m_mutex;

public:
    background_task(const std::string& task_name ):name(task_name) {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::cout <<  name.c_str() << " is constructed" << name.c_str() << std::endl;
    }
    void operator()() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::cout <<  name.c_str() << " is running" << std::endl;
    }
};

void func(int i , int delay ) {

    for(int j = 0 ; j < i ; ++j ) {
        std::cout << "func is runnning on the thread " << std::this_thread::get_id() <<  std::endl;
        std::this_thread::sleep_for( std::chrono::milliseconds(delay));
    }

}


int main(int argc , char* argv[] ) {

    try {
        std::thread t(func, RandomNumber::Generate( 1 , 10 ) , RandomNumber::Generate(400 , 1200) );
        background_task b("background_task");
        std::thread t2{ std::ref( b )};
        t.join();
        t2.join();
    }

    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}
