#include <iostream>
#include <string>
#include <fstream>
#include "DataFrame.h"

int main()
{
    jjn<double> myVector; // 벡터 객체 생성(double 타입)
    std::string input;
    double num;
    int index;

    while(1)
    {
        // 아래는 명령어를 입력받고 함수 실행하여 작업 수행
        std::cout << "수행할 작업을 입력해주세요" << std::endl;
        std::cin >> input;

        if (input == "push_back")
        {
            std::cout << "데이터를 입력해주세요: ";
            std::cin >> num;
            myVector.push_back(num);
        }
        else if(input == "at")
        {
            std::cout << "인덱스를 입력해주세요: ";
            std::cin >> index;
            std::cout << myVector.at(index) << std::endl;
        }
        else if(input == "begin")
        {
            std::cout << "첫 번째 요소: " << *myVector.begin() << std::endl;
        }
        else if(input == "end")
        {
            std::cout << "마지막 요소: " << *(myVector.end() - 1) << std::endl;
        }
        else if(input == "empty")
        {
            if(myVector.empty() == 0)
            {
                std::cout << "비어있지 않음" << std::endl;
            }
            if(myVector.empty() == 1)
            {
                std::cout << "비어있음" << std::endl;
            }
        }
        else if(input == "erase")
        {
            std::cout << "삭제할 인덱스를 입력해주세요: ";
            std::cin >> index;
            myVector.erase(index);
        }
        else if(input == "insert")
        {
            std::cout << "삽입할 인덱스를 입력해주세요: ";
            std::cin >> index;
            std::cout << "삽입할 값을 입력해주세요: ";
            std::cin >> num;
            myVector.insert(index, num);
        }
        else if(input == "size")
        {
            std::cout << "크기: " << myVector.size() << std::endl;
        }
        else if(input == "save") // 벡터를 파일에 저장
        {
            std::ofstream outFile("vector.txt"); // 파일 열기
            for (size_t i = 0; i < myVector.size(); ++i)
            {
                outFile << myVector.at(i) << " ";//파일 작성
            }
            std::cout << std::endl;
            outFile.close();
        }
        else if(input == "load") // 파일에서 벡터 불러오기
        {
            std::ifstream inFile("vector.txt"); // 파일 열기
            myVector.clear(); // 기존 벡터 데이터 초기화
            while (inFile >> num) // 파일에서 데이터 읽기
            {
                myVector.push_back(num);
            }
            inFile.close();
        }
    }
    return 0;
}
