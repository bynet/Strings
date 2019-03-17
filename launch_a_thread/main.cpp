
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello world" << std::endl;
}

class bakground_task{

    void do_something( ) const {
        std::cout << "do_something( )" << std::endl;
    }

    public:
    void operator( )( ) const {
        do_something();
    }
    
};

int main( int argc , char* argv[] ) {

    std::thread t( hello );
    std::thread y{ bakground_task() };
    t.join();
    y.join();
  
}
