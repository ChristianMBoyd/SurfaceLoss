#include <iostream>
#include "Test.h"
#include "TestInputStructs.h"
#include "TestMatrix.h"

void holdOutputWindow();
void testComponents();

int main()
{
    testComponents();
    holdOutputWindow();
    return 0;
}

void testComponents() {
    Test baseTest;
    TestMatrix matrixTest;
    TestInputStructs inputStructTest;

    baseTest.runTests();
    matrixTest.runTests();
    inputStructTest.runTests();
}

void holdOutputWindow() {
    std::cout << "Enter anything to close." << std::endl;
    std::string inputNeededToClose;
    std::cin >> inputNeededToClose;
}