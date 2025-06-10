#include "Teacher.h"

Teacher::Teacher(const std::string& n, const std::string& d, int exp) 
    : name(n), department(d), experienceYears(exp) {
}

std::string Teacher::getName() const {
    return name;
}

std::string Teacher::getDepartment() const {
    return department;
}

int Teacher::getExperience() const {
    return experienceYears;
}

void Teacher::setName(const std::string& n) {
    name = n;
}

void Teacher::setDepartment(const std::string& d) {
    department = d;
}

void Teacher::setExperience(int exp) {
    experienceYears = exp;
}