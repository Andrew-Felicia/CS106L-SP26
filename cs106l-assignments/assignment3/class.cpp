#include "class.h"
#include <iostream>

coffee_shop::coffee_shop(std::string name, int coffee_kinds) {
    this->name = name;
    this->coffee_kinds = coffee_kinds;
}

//the default coffee shop is luckin coffee!.
coffee_shop::coffee_shop() {
    this->name = "lukin coffee";
    this->coffee_kinds = 20;
}

coffee_shop::~coffee_shop()
{
}

void coffee_shop::say_slogan() {
    std::cout<< "build your own coffee shop!" << '\n';
}


std::string coffee_shop::get_name() const{
    return this->name;
}

int coffee_shop::get_kinds() const {
    return this->coffee_kinds;
}


void coffee_shop::set_kinds(int kinds) {
    this->coffee_kinds = kinds;
}

void coffee_shop::set_name(std::string name) {
    this->name = name;
}