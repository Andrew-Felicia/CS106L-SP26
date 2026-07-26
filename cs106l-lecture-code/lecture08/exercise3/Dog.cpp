#include "Dog.h"
#include <iostream>

// TODO: Implement the constructor
// Call the base class Animal constructor with the name argument
Dog::Dog(std::string name) : Animal(name) {

}

// TODO: speak() — print "Woof!"
void Dog::speak() const {
    std::cout<< "Woof!" << '\n';
}

// TODO: move() — print "runs on all fours"
void Dog::move() const {
    std::cout<< "runs on all fours" << '\n';
}

// TODO: getType() — return the string "Dog"
std::string Dog::getType() const {
    return "Dog";
}

// TODO: fetch() — print "...fetches the ball!"
void Dog::fetch() const {
    std::cout<< "...fetches the ball!" << '\n';
}
