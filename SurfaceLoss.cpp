// SurfaceLoss.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Test.h"
#include "TestInputStructs.h"
#include "TestLinearAlgebra.h"

void holdOutputWindow();

int main()
{
    TestLinearAlgebra linearAlgebraTest;
    TestInputStructs inputStructTest;
    
    linearAlgebraTest.runTests();
    inputStructTest.runTests();

    holdOutputWindow();
    return 0;
}

void holdOutputWindow() {
    std::cout << "Enter anything to close." << std::endl;
    std::string inputNeededToClose;
    std::cin >> inputNeededToClose;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu