#include <string>

template<typename T> void EQ_TEST(T input, T expected, std::string tag)
{
    if(input != expected) 
        std::cout << "[FAILED] input [" << input << "]"
         << " expected [" << expected << "]" << " TAG [" 
         << tag << "]" << std::endl;

    else
         std::cout << "[PASSED] input [" << expected << "]"
         << " expected [" << input << "]" << " TAG [" << tag << "]" << std::endl;
}