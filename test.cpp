#include <iostream>
#include <string>

int main()
{
    std::string str(100, 'a');     // Create a string of 100 'a' characters
    std::cout << str << std::endl; // Output: aaaaaaaaaa... (100 times)
    return 0;
}
