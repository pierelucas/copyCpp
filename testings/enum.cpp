#include <iostream>

int main(void)
{
    enum test 
    {
        peter = 1,
        klaus,
        marvin
    };

    std::cout << peter << std::endl;
    std::cout << klaus << std::endl;

    return(EXIT_SUCCESS); 
}
