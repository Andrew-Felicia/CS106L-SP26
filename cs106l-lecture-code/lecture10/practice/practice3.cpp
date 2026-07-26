/*
 * CS106L - Template Functions Practice
 * Problem 3: Add a Concept
 *
 * The function below works correctly when T supports ==,
 * but gives a confusing error message if T does not.
 *
 * Tasks:
 *   1. Define a concept called `EqualityComparable` that requires
 *      operator== to exist and return something bool-like.
 *   2. Apply your concept to the `allEqual` function.
 *   3. Uncomment the broken call in main() and observe the new,
 *      cleaner error message.
 *
 * Compile with: clang++ -std=c++20 problem3.cpp
 */

#include <iostream>
#include <string>
#include <concepts>


template <typename T>
concept EqualityComparable = requires(const T a, const T b) {
    {a == b} -> std::convertible_to<bool>;
};


template <EqualityComparable T>
bool allEqual(const T& a, const T& b, const T& c) {
    return a == b && b == c;
}

// This struct intentionally has no operator== defined
struct NoEquals {
    int value;

    bool operator==(const NoEquals& other) const {
        return value == other.value;
    }
};

int main() {
    std::cout << std::boolalpha; //without this line will output: 1 0 1
    std::cout << allEqual(1, 1, 1)                              << std::endl; // true
    std::cout << allEqual(1, 2, 1)                              << std::endl; // false
    // std::cout << allEqual(std::string("hi"), std::string("hi"), std::string("hi")) << std::endl; // true, works. implicit instantiation.
    std::cout << allEqual<std::string>("hi", "hi", "hi") << std::endl; // true, works. explicit instantiation.

    // TODO: uncomment this line and observe the error message
    // With your concept, it should clearly say NoEquals doesn't satisfy EqualityComparable
    // Without your concept, the error points deep inside the function body
    NoEquals a{1}, b{2}, c{1};
    std::cout << allEqual(a, b, c) << std::endl;

    return 0;
}
