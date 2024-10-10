#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
protected:
    std::string name;
    std::string birth_day;
    int student_number;
public:
    // 기본 생성자
    Student();

    // student 생성자,이름,생일,전화번호
    Student(const std::string& name, const std::string& birth_day, int student_number);

    // Get함수,protected의 변수를 가져오는 용
    std::string getName() const;
    std::string getBirthDay() const;
    int getStudentNumber() const;
};

#endif
