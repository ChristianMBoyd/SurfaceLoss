#include <iostream>
#include "Test.h"
#include "TestRandomGenerator.h"
#include "TestInputStructs.h"
#include "TestMatrix.h"

void holdOutputWindow();
void testComponents();

int main() {
    testComponents();
    holdOutputWindow();
    return 0;
}

void testComponents() {
    Test baseTest;
    TestRandomGenerator randomGeneratorTest(1, 100); // testing positives
    TestInputStructs inputStructTest;
    TestMatrix matrixTest;

    baseTest.runTests();
    randomGeneratorTest.runTests();
    inputStructTest.runTests();
    matrixTest.runTests();
}

void holdOutputWindow() {
    std::cout << "Enter anything to close." << std::endl;
    std::string inputNeededToClose;
    std::cin >> inputNeededToClose;
}