#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
private:
    std::string name;
    std::string department;
    int experienceYears;

public:
    Teacher(const std::string& n, const std::string& d, int exp);
    
    std::string getName() const;
    std::string getDepartment() const;
    int getExperience() const;
    
    void setName(const std::string& n);
    void setDepartment(const std::string& d);
    void setExperience(int exp);
};

#endif // TEACHER_H