
#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Tokenizer{

    const string& m_str;
    const string m_delim ; 
    size_t m_lastTokenPosition {0} ;

    inline size_t start_of_token(size_t pos) {
        return m_str.find_first_not_of( m_delim , pos );
    }

    inline size_t end_of_token(size_t pos) {
        return m_str.find_first_of( m_delim , pos );
    }


public:

    Tokenizer(const string& str , const string& delim = " \f\n\r\t\v" )
        :m_str(str)
        ,m_lastTokenPosition(0)
        ,m_delim(delim){
        
    }

    string getNextToken() {

        if( m_lastTokenPosition == string::npos ) {
            return string{""};
        }

        auto start = start_of_token( m_lastTokenPosition);
        if( start == string::npos ) {
            return string{""};
        }

        auto end   = end_of_token(start);
        m_lastTokenPosition = end ; 

        return m_str.substr( start , end - start );

    }

    vector<string> getAllTokens() {
        string token ; 
        vector<string> results ; 
        while( !(token = this->getNextToken() ).empty() )
            results.emplace_back(token);

        return results;
    }

};

int main(int argc , char* argv[] ) {

    string s = "xxyy aabb,ccdd eeeeff gg";

    Tokenizer tokenizer(s , " ,");

    vector<string> tokens = tokenizer.getAllTokens();
    for(auto& t : tokens ) {
        cout << t.c_str() << endl ;
    }

}
