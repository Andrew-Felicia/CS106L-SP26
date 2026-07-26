/* File: main.cpp
 * Author: Preston Seay
 *
 * This file uses your bounded value template with ints.
 */
//#include "bounded_value.h"
#include "bounded_value.cpp"
#include <iostream>

int main() {
    //test for int
    // BoundedValue<int> health(120, 0, 100);

    // std::cout << health.get() << std::endl; // expected: 100
    // health.printAllValue();

    // health.set(-10);
    // std::cout << health.get() << std::endl; // expected: 0
    // health.printAllValue();

    // health.set(50);
    // std::cout << health.get() << std::endl; // expected: 50
    // health.printAllValue();

    // health.adjust(60);
    // std::cout << health.get() << std::endl; // expected: 100 (if implemented)
    // health.printAllValue();

    // return 0;

    //test for double
    BoundedValue<int> health(120.0, 0.0, 100.0);

    std::cout << health.get() << std::endl; // expected: 100.0
    health.printAllValue();

    health.set(-10.0);
    std::cout << health.get() << std::endl; // expected: 0.0
    health.printAllValue();

    health.set(50.0);
    std::cout << health.get() << std::endl; // expected: 50.0
    health.printAllValue();

    health.adjust(60.0);
    std::cout << health.get() << std::endl; // expected: 100.0
    health.printAllValue();

    return 0;
}