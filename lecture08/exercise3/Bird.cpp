#include "Bird.h"
#include <iostream>

// TODO: Implement the constructor
// Call the base class Animal constructor with the name argument
Bird::Bird(std::string name) : Animal(name) {
    
}


// TODO: speak() — print "Tweet!"
void Bird::speak() const {
    std::cout<< "Tweet!" << '\n';
}

// TODO: move() — print "soars through the air"
void Bird::move() const {
    std::cout<< "soars through the air" << '\n';
}

// TODO: getType() — return the string "Bird"
std::string Bird::getType() const {
    return "Bird";
}

// TODO: migrate() — print "Heading south for winter!"
void Bird::migrate() const {
    std::cout<< "Heading south for winter!" << '\n';
}
