#include <iostream>

#include "modulo.hpp"

int main() {
    Modulo a;
    Modulo b;
    Modulo c;

    std::cin >> a >> b;

    std::cout << "Addition:" << std::endl;
    c = a + b;
    std::cout << c << std::endl;

    std::cout << "Subtraction:" << std::endl;
    c = a - b;
    std::cout << c << std::endl;

    std::cout << "Multiplication:" << std::endl;
    c = a * b;
    std::cout << c << std::endl;

    std::cout << "Division:" << std::endl;
    c = a / b;
    if(c.GetMod()) {
        std::cout << c << std::endl;
    }

    if(a == b) {
        std::cout << "Numbers are equal" << std::endl;
    }

    if(a > b) {
        std::cout << "First number is greater" << std::endl;
    }
    
    if(a < b) {
        std::cout << "First number is less" << std::endl;
    }

    return 0;
}
