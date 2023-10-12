// SurfaceLoss.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Test.h"
#include "TestInputStructs.h"

int main()
{
    TestInputStructs test;
    test.runTests();
    std::cout << "Enter anything to close." << std::endl;
    std::string anythingInputToClose;
    std::cin >> anythingInputToClose;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu