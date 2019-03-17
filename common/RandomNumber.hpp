
#include <random>
#include <stdexcept>

class RandomNumber{
public:
    static int Generate(unsigned int lower_limit , unsigned int upper_limit ) {

        if( upper_limit <= lower_limit )
            throw std::invalid_argument( ErrorMessage() << "upperlimit " << upper_limit << " can not be smaller than lowerlimit " << lower_limit  ) ;
        std::srand(std::time(0));
        return  ( lower_limit + (std::rand() % (upper_limit - lower_limit ))); 
    }

};

