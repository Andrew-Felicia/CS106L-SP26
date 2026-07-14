#include <iostream>

int main() {
	// Uniform Initialization, will fail
	// int numOne{12.0};
	// float numTwo{12.0};

	// int numOne(12.1);
	// float numTwo(12.1);

	float numTwo = 12.1;
	int numOne = static_cast(int)(numTwo);

	std::cout << "numOne is: " << numOne << std::endl;
	std::cout << "numTwo is: " << numTwo << std::endl;
	return 0;
}
