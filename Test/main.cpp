#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

template <class Type>
Type add(Type num, Type num2){
    return num+num2;
}