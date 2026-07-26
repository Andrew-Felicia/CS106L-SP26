/*
 * CS106L - Template Functions Practice
 * Problem 1: Fix the Template
 *
 * The following code has a bug. The program compiles but produces
 * incorrect / unpredictable results.
 *
 * Tasks:
 *   1. Run the code and observe the output.
 *   2. Explain WHY the output is wrong.
 *   3. Fix the code so it correctly returns "apple".
 *
 * Hint: What type does the compiler deduce for T?
 *       What does operator< actually do on that type?
 */

#include <iostream>
#include <string>
#include <concepts>



template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {

    auto result = min<std::string>("apple", "banana"); //const char* gets converted to std::string here.
    std::cout << "min(\"apple\", \"banana\") = " << result << std::endl;

    return 0;
}
