// SurfaceLoss.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "PlanarWavevector.h"
#include "Test.h"

int main()
{
    Test test;
    test.runTests();
    std::cout << "Enter anything to close." << std::endl;

    std::string input;
    std::cin >> input;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu