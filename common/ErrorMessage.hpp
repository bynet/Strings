#include <sstream>
#include <string>

class ErrorMessage {
    std::stringstream m_sstream;
public:
    template <typename T>
    ErrorMessage& operator<<(const T& value) {
        m_sstream << value;
        return *this;
    }

    operator std::string() const {
        return m_sstream.str();
    }
};

