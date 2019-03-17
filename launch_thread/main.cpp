#include <thread>
#include <iostream>
#include <random>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <ErrorMessage.hpp>
#include <mutex> 
#include <RandomNumber.hpp>

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
