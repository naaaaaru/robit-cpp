#include "student.h"

Student::Student() : name(""), birth_day(""), student_number(0) {}//생성자

// 인자를 받는 생성자 정의
Student::Student(const std::string& name, const std::string& birth_day, int student_number)
    : name(name), birth_day(birth_day), student_number(student_number) {}

// Get 함수 정의
std::string Student::getName() const
{
    return name;
}

std::string Student::getBirthDay() const
{
    return birth_day;
}

int Student::getStudentNumber() const
{
    return student_number;
}
