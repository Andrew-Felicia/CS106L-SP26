#include "Cat.h"
#include <iostream>

// TODO: Implement the constructor
// Call the base class Animal constructor with the name argument
Cat::Cat(std::string name) : Animal(name) {

}

// TODO: speak() — print "Meow!"
void Cat::speak() const {
    std::cout<< "Meow!" << '\n';
}

// TODO: move() — print "slinks gracefully"
void Cat::move() const {
    std::cout<< "slinks gracefully" << '\n';
}

// TODO: getType() — return the string "Cat"
std::string Cat::getType() const {
    return "Cat";
}

// TODO: purr() — print "Purrrrr..."
void Cat::purr() const {
    std::cout << "Purrrrr..." << '\n';
}
