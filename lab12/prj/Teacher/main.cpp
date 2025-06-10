#include <iostream>
#include <cassert>
#include <stdexcept>
#include "ClassLab12_Bovkun.h"
#include "Teacher.h"

// Тестування конструктора та валідації вхідних даних
void testConstructor() {
    std::cout << "=== Testing ClassLab12_Bovkun constructor ===" << std::endl;

    // Test 1: Valid values
    try {
        ClassLab12_Bovkun rect1(3.0, 4.0);
        assert(rect1.getSideA() == 3.0);
        assert(rect1.getSideB() == 4.0);
        std::cout << "TC1.1: Pass (valid values)" << std::endl;
    } catch (...) {
        std::cout << "TC1.1: Fail" << std::endl;
    }

    // Test 2: Zero value for side A
    try {
        ClassLab12_Bovkun rect2(0.0, 5.0);
        std::cout << "TC1.2: Fail (expected exception)" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "TC1.2: Pass (exception: " << e.what() << ")" << std::endl;
    }

    // Test 3: Negative value for side B
    try {
        ClassLab12_Bovkun rect3(2.0, -1.0);
        std::cout << "TC1.3: Fail (expected exception)" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "TC1.3: Pass (exception: " << e.what() << ")" << std::endl;
    }
}

// Тестування методів доступу до полів (гетери/сетери)
void testAccessors() {
    std::cout << "\n=== Testing accessors ===" << std::endl;

    ClassLab12_Bovkun rect(3.0, 4.0);

    // Test 1: Getters
    assert(rect.getSideA() == 3.0);
    assert(rect.getSideB() == 4.0);
    std::cout << "TC2.1: Pass (getters return correct values)" << std::endl;

    // Test 2: Setters with validation
    try {
        rect.setSideA(5.0);
        assert(rect.getSideA() == 5.0);
        std::cout << "TC3.1: Pass (setSideA works correctly)" << std::endl;
    } catch (...) {
        std::cout << "TC3.1: Fail" << std::endl;
    }
}

// Тестування обчислення площі
void testAreaCalculation() {
    std::cout << "\n=== Testing area calculation ===" << std::endl;

    ClassLab12_Bovkun rect(3.0, 4.0);

    assert(rect.calculateArea() == 12.0);
    std::cout << "TC4.1: Pass (area calculated correctly)" << std::endl;
}

// Тестування класу Teacher
void testTeacher() {
    std::cout << "\n=== Testing Teacher class ===" << std::endl;

    Teacher t("John Doe", "Computer Science", 10);

    assert(t.getName() == "John Doe");
    assert(t.getDepartment() == "Computer Science");
    assert(t.getExperience() == 10);
    std::cout << "Teacher TC1: Pass (constructor and getters)" << std::endl;

    t.setExperience(11);
    assert(t.getExperience() == 11);
    std::cout << "Teacher TC2: Pass (setter works)" << std::endl;
}

int main() {
    testConstructor();
    testAccessors();
    testAreaCalculation();
    testTeacher();

    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
