#include <iostream>
#include <vector>//push_back,begin,end
#include <algorithm>//sort
#include "student.h"

int main()
{
    std::vector<Student> students;
    for (int i = 0; i < 3; ++i)
    {
            std::string name, birth_day;
            int student_number;

            std::cout << i + 1 << "번째 학생의 이름을 입력하세요: ";
            std::cin >> name;

            std::cout << i + 1 << "번째 학생의 생년월일 입력하세요: ";
            std::cin >> birth_day;

            std::cout << i + 1 << "번째 학생의 학번을 입력하세요: ";
            std::cin >> student_number;

            // 입력받은 정보로 Student 객체 생성 후 벡터에 추가
            students.push_back(Student(name, birth_day, student_number));
        }

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b)// 람다식,학생 벡터의 시작부터 끝까지 더 앞순의 이름을 반환
    {
        return a.getName() < b.getName();//get함수로 변수를 가져와 비교
    });

    std::cout << "이름 기준 정렬 결과:"<< std::endl;
    for (const auto& student : students)
    {
        std::cout << student.getName() << "/" << student.getBirthDay() << "/" << student.getStudentNumber() << std::endl;
    }

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b)// 람다식을 사용해 더 빠른 생년월일을 반환
    {
        return a.getBirthDay() < b.getBirthDay();
    });

    std::cout << "생년월일 기준 정렬 결과:"<< std::endl;
    for (const auto& student : students)
    {
        std::cout << student.getName() << "/" << student.getBirthDay() << "/" << student.getStudentNumber() << std::endl;
    }

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b)// 람다식을 사용해 더 작은 학번을 반환
    {
        return a.getStudentNumber() < b.getStudentNumber();
    });

    std::cout << "학번 기준 정렬 결과:" << std::endl;
    for (const auto& student : students)
    {
        std::cout << student.getName() << "/" << student.getBirthDay() << "/" << student.getStudentNumber() << std::endl;
    }

    return 0;
}
