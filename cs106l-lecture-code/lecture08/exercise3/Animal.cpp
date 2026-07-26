#include "Animal.h"
#include <iostream>

// TODO: Implement the constructor
// Store the name parameter into the protected member variable
Animal::Animal(std::string name) {
    this->name = name;
}

// void Animal::speak() const{
//     std::cout<< "123 from Animal classes" <<'\n';
// }

// TODO: Implement the destructor
// It doesn't need to do anything — but it must be defined since it's virtual
Animal::~Animal() {
    
}

// TODO: Implement getName()
// Return the animal's name
std::string Animal::getName() const {
    return this->name;
}

// TODO: Implement introduce()
// Print one line in this format:
//   Hi, I'm Buddy! Woof! ...and I run on all fours.
//
// Call this->speak() and this->move() — do NOT hardcode any sounds or movements.
// Virtual dispatch will automatically call the right derived class version at runtime.
void Animal::introduce() const {
    std::cout << "Hi, I'm Buddy! Woof! ...and I run on all fours." << '\n';
    this->speak();
    this->move();
}
