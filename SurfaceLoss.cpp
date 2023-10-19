#include <iostream>
#include "Test.h"
#include "TestInputStructs.h"
#include "TestLinearAlgebra.h"
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
    TestMatrix matrixTest;
    TestLinearAlgebra linearAlgebraTest;
    TestInputStructs inputStructTest;

    matrixTest.runTests();
    linearAlgebraTest.runTests();
    inputStructTest.runTests();
}

void holdOutputWindow() {
    std::cout << "Enter anything to close." << std::endl;
    std::string inputNeededToClose;
    std::cin >> inputNeededToClose;
}