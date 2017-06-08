#include <iostream>
#include "Engine.h"

//using namespace Beserk;

bool TestMe() {
	std::cout << "Testing Program" << std::endl;
	std::cout << "size of bool: " << sizeof(bool) << std::endl;
	std::cout << "size of unsigned char: " << sizeof(unsigned char) << std::endl;
	std::cout << "size of unsigned int: " << sizeof(unsigned int) << std::endl;
	std::cout << "size of double: " << sizeof(double) << std::endl;

	

	// Start Engine
	// Beserk::Engine->start();
	
	return EXIT_SUCCESS;
};

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
//};