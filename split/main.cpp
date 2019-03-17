
#include <string>
#include <iostream>
#include <vector>


class String{

    std::string s;
public:
    String( const std::string& s ):s( s ) {

    } 
    
    // String to_lower_copy() const {
        // return { boost::to_lower_copy(s)} ; 
    // }


    std::vector<String> split( const std::string& delim=" ") {
        std::vector<std::string> parts ;
        
        std::size_t i = 0 ;
        std::size_t j = s.find_first_of(delim) ;

        while( j != std::string::npos ) {
            
            std::cout << "j : " << j << std::endl ;
            
            parts.push_back( s.substr( i , j - i ) );
            i = ++j ;
            

            j = s.find_first_of(delim , i ) ;
            if( ( j ==  std::string::npos ) && (i < s.length() ) ) {
                parts.push_back( s.substr( i , s.length() - i  ));
            }
        }

        return std::vector<String>( parts.begin() , parts.end() );
        
    }

    size_t length() {
        return s.length();
    }

    friend std::ostream& operator<<(std::ostream& os , const String& p ){
        os << p.s ;
        return os;
    }
};


int main(int argc , char* argv[] ) {

    std::vector<String> words;
    String s(std::string{"Account Name|Address 1|Address 2|City"} );

    words = s.split("|");

    for(auto& w : words ) {
        std::cout << w << std::endl;
    }

    
    


}
