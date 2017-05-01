#include <iostream>
#include "CEngine.h"

using namespace Beserk;

bool TestMe() {
	std::cout << "Testing Program" << std::endl;

	return EXIT_SUCCESS;
}

//int main(int argc, char* args[]) {
//
//	std::cout << "Testing the tester program." << std::endl;
//
//	int number_one = 10;
//	int number_two = 32;
//
//	Beserk::CTest test;
//
//	int added_number = test.AddThese(number_one, number_two);
//	std::cout << "Added Number: " << added_number << std::endl;
//
//	// Get some numbers
//
//	std::cout << "Enter Some Numbers: ";
//	int some_numbers;
//	std::cin >> some_numbers;
//
//	std::cout << "The numbers you entered were: " << some_numbers << std::endl;
//
//	std::cin.ignore();
//
//	return 0;
//}