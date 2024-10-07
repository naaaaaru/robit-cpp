#include "calcul.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

enum Mode { CALCULATOR, CONVERTER, STATISTICS };

void lengthConverter(Calc& calc, double value, char unit);
void temperatureConverter(Calc& calc, double value, char unit);
void weightConverter(Calc& calc, double value, char unit);
void statisticsMode(Calc& calc);

int main()
{
    Calc calc;
    Mode mode = CALCULATOR;
    std::string input;
    double val, min, max;

    std::cout << "모드를 전환하려면 'mode'를 입력하세요. 종료하려면 'quit'를 입력하세요." << std::endl;

    while (true)
    {
        if (mode == CALCULATOR)
        {
            std::cout << "[계산기 모드] 현재 결과: " << calc.getRes() << std::endl;
            std::cout << "연산을 선택하세요 (add, sub, mul, div, sqrt, pow, fact, sin, cos, tan, log, ln, rand, pi, clear, mode): ";
            std::cin >> input;

            if (input == "quit")
            {
                std::cout << "프로그램을 종료합니다." << std::endl;
                break;
            }
            else if (input == "mode")
            {
                mode = CONVERTER;
                std::cout << "단위 변환 모드로 전환합니다." << std::endl;
                continue;
            }
            else if (input == "clear")
            {
                calc.clear();
                std::cout << "결과가 초기화되었습니다." << std::endl;
                continue;
            }

            if (input == "rand")
            {
                std::cout << "최소값을 입력하세요: ";
                std::cin >> min;
                std::cout << "최대값을 입력하세요: ";
                std::cin >> max;
                calc.rand(min, max);
            }
            else if (input == "sqrt")
            {
                calc.sqrt();
            }
            else if (input == "fact")
            {
                calc.fact();
            }
            else if (input == "sin")
            {
                calc.sin();
            }
            else if (input == "cos")
            {
                calc.cos();
            }
            else if (input == "tan")
            {
                calc.tan();
            }
            else if (input == "log")
            {
                calc.log10();
            }
            else if (input == "ln")
            {
                calc.ln();
            }
            else if (input == "pi")
            {
                calc.add(calc.pi());
            }
            else
            {
                std::cout << "값을 입력하세요: ";
                if (!(std::cin >> val))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "잘못된 입력입니다. 숫자를 입력하세요." << std::endl;
                    continue;
                }
                try
                {
                    if (input == "add")
                    {
                        calc.add(val);
                    }
                    else if (input == "sub")
                    {
                        calc.sub(val);
                    }
                    else if (input == "mul")
                    {
                        calc.mul(val);
                    }
                    else if (input == "div")
                    {
                        calc.div(val);
                    }
                    else if (input == "pow")
                    {
                        calc.pow(val);
                    }
                    else
                    {
                        std::cout << "잘못된 명령입니다." << std::endl;
                    }
                }
                catch (const std::exception& e)
                {
                    std::cout << "오류: " << e.what() << std::endl;
                }
            }
        }
        else if (mode == CONVERTER)
        {
            std::cout << "[단위 변환 모드] 길이단위(c(cm),m,k(km),f,i) 온도단위(K,F,C) 무게단위(g,k(kg),p), mode: 통계 모드로 전환: ";
            std::cin >> input;

            if (input == "mode")
            {
                mode = STATISTICS;
                std::cout << "통계 모드로 전환합니다." << std::endl;
                continue;
            }

            double value;
            char unit;
            std::cout << "변환할 값을 입력하세요: ";
            std::cin >> value >> unit;

            if (unit == 'i' || unit == 'm' || unit == 'f' || unit == 'c' || unit == 'k')
            {
                lengthConverter(calc, value, unit);
            }
            else if (unit == 'C' || unit == 'F' || unit == 'K')
            {
                temperatureConverter(calc, value, unit);
            }
            else if (unit == 'k' || unit == 'g' || unit == 'p')
            {
                weightConverter(calc, value, unit);
            }
            else
            {
                std::cout << "잘못된 단위입니다." << std::endl;
            }
        }
        else if (mode == STATISTICS)
        {
            statisticsMode(calc);
            std::cout << "계산기 모드로 돌아갑니다." << std::endl;
            mode = CALCULATOR;
        }
    }

    return 0;
}

void lengthConverter(Calc& calc, double value, char unit)
{
    std::string targetUnit;
    std::cout << "어떤 단위로 변환하시겠습니까? (m: 미터, i: 인치, f: 피트, cm: 센티미터, km: 킬로미터): ";
    std::cin >> targetUnit;

    double result = 0;

    switch (unit)
    {
        case 'i':
            if (targetUnit == "m")
                result = calc.inchToMeter(value);
            else if (targetUnit == "f")
                result = value / 12;  // 인치를 피트로 변환
            else if (targetUnit == "cm")
                result = calc.inchToMeter(value) * 100; // 인치를 센티미터로 변환
            else if (targetUnit == "km")
                result = calc.inchToMeter(value) / 1000; // 인치를 킬로미터로 변환
            break;
        case 'm':
            if (targetUnit == "i")
                result = calc.meterToInch(value);
            else if (targetUnit == "f")
                result = value * 3.28084; // 미터를 피트로 변환
            else if (targetUnit == "cm")
                result = value * 100; // 미터를 센티미터로 변환
            else if (targetUnit == "km")
                result = value / 1000; // 미터를 킬로미터로 변환
            break;
        case 'f':
            if (targetUnit == "i")
                result = value * 12; // 피트를 인치로 변환
            else if (targetUnit == "m")
                result = value / 3.28084; // 피트를 미터로 변환
            else if (targetUnit == "cm")
                result = value * 30.48; // 피트를 센티미터로 변환
            else if (targetUnit == "km")
                result = (value / 3.28084) / 1000; // 피트를 킬로미터로 변환
            break;
        case 'c':
            if (targetUnit == "i")
                result = calc.meterToInch(value / 100); // 센티미터를 인치로 변환
            else if (targetUnit == "m")
                result = value / 100; // 센티미터를 미터로 변환
            else if (targetUnit == "f")
                result = value / 30.48; // 센티미터를 피트로 변환
            else if (targetUnit == "km")
                result = (value / 100) / 1000; // 센티미터를 킬로미터로 변환
            break;
        case 'k':
            if (targetUnit == "m")
                result = value * 1000; // 킬로미터를 미터로 변환
            else if (targetUnit == "i")
                result = calc.meterToInch(value * 1000); // 킬로미터를 인치로 변환
            else if (targetUnit == "f")
                result = (value * 1000) * 3.28084; // 킬로미터를 피트로 변환
            else if (targetUnit == "cm")
                result = value * 100000; // 킬로미터를 센티미터로 변환
            break;
    }
    std::cout << "변환 결과: " << result << " " << targetUnit << std::endl;
}

void temperatureConverter(Calc& calc, double value, char unit)
{
    std::string targetUnit;
    std::cout << "어떤 단위로 변환하시겠습니까? (C: 섭씨, F: 화씨, K: 켈빈): ";
    std::cin >> targetUnit;

    double result = 0;

    switch (unit)
    {
        case 'C':
            if (targetUnit == "F")
                result = calc.celsiusToFahrenheit(value);
            else if (targetUnit == "K")
                result = value + 273.15; // 섭씨를 켈빈으로 변환
            break;
        case 'F':
            if (targetUnit == "C")
                result = calc.fahrenheitToCelsius(value);
            else if (targetUnit == "K")
                result = (value - 32) * 5.0 / 9.0 + 273.15; // 화씨를 켈빈으로 변환
            break;
        case 'K':
            if (targetUnit == "C")
                result = value - 273.15; // 켈빈을 섭씨로 변환
            else if (targetUnit == "F")
                result = (value - 273.15) * 9.0 / 5.0 + 32; // 켈빈을 화씨로 변환
            break;
    }
    std::cout << "변환 결과: " << result << " " << targetUnit << std::endl;
}

void weightConverter(Calc& calc, double value, char unit)
{
    std::string targetUnit;
    std::cout << "어떤 단위로 변환하시겠습니까? (k: 킬로그램, g: 그램, p: 파운드): ";
    std::cin >> targetUnit;

    double result = 0;

    switch (unit)
    {
        case 'k':
            if (targetUnit == "g")
                result = calc.kilogramToGram(value); // 킬로그램을 그램으로 변환
            else if (targetUnit == "p")
                result = calc.kilogramToPound(value); // 킬로그램을 파운드로 변환
            break;
        case 'g':
            if (targetUnit == "kg")
                result = calc.gramToKilogram(value); // 그램을 킬로그램으로 변환
            else if (targetUnit == "p")
                result = calc.gramToPound(value); // 그램을 파운드로 변환
            break;
        case 'p':
            if (targetUnit == "kg")
                result = calc.poundToKilogram(value); // 파운드를 킬로그램으로 변환
            else if (targetUnit == "g")
                result = calc.poundToGram(value); // 파운드를 그램으로 변환
            break;
    }
    std::cout << "변환 결과: " << result << " " << targetUnit << std::endl;
}

void statisticsMode(Calc& calc)
{
    int n;
    std::cout << "[통계 모드] 숫자의 갯수를 입력하세요: ";
    std::cin >> n;

    std::vector<double> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << (i+1) << "번째 숫자를 입력하세요: ";
        std::cin >> numbers[i];
    }

    std::string operation;
    std::cout << "계산할 항목을 선택하세요 (average, stddev, median, max, min): ";
    std::cin >> operation;

    if (operation == "average")
        std::cout << "평균: " << calc.average(numbers) << std::endl;
    else if (operation == "stddev")
        std::cout << "표준편차: " << calc.standardDeviation(numbers) << std::endl;
    else if (operation == "median")
        std::cout << "중앙값: " << calc.median(numbers) << std::endl;
    else if (operation == "max")
        std::cout << "최댓값: " << calc.max(numbers) << std::endl;
    else if (operation == "min")
        std::cout << "최솟값: " << calc.min(numbers) << std::endl;
    else
        std::cout << "잘못된 명령입니다." << std::endl;
}
