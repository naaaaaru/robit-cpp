#include "calcul.h"
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

Calc::Calc() : result(0)
{
    std::srand(std::time(0));
}

// 기본 계산기 기능
double Calc::add(double num)
{
    result += num;
    return result;
}
double Calc::sub(double num)
{
    result -= num;
    return result;
}
double Calc::mul(double num)
{
    result *= num;
    return result;
}
double Calc::div(double num)
{
    if (num == 0) throw std::invalid_argument("0으로 나눌 수 없습니다.");
    result /= num;
    return result;
}
double Calc::sqrt()
{
    if (result < 0) throw std::invalid_argument("음수의 제곱근은 불가능");
    result = std::sqrt(result);
    return result;
}
double Calc::pow(double num)
{
    result = std::pow(result, num);
    return result;
}
double Calc::fact()
{
    if (result < 0 || std::floor(result) != result) throw std::invalid_argument("음수나 소수의 팩토리얼 불가능");
    result = std::tgamma(result + 1);
    return result;
}
double Calc::sin()
{
    result = std::sin(result);
    return result;
}
double Calc::cos()
{
    result = std::cos(result);
    return result;
}
double Calc::tan()
{
    result = std::tan(result);
    return result;
}
double Calc::log10()
{
    if (result <= 0) throw std::invalid_argument("로그는 0 이하에서 불가");
    result = std::log10(result);
    return result;
}
double Calc::ln()
{
    if (result <= 0) throw std::invalid_argument("로그는 0 이하에서 불가");
    result = std::log(result);
    return result;
}
double Calc::rand(double min, double max)
{
    result = min + (std::rand() / (RAND_MAX / (max - min)));
    return result;
}
double Calc::pi() const
{
    return 3.141593;
}
double Calc::getRes()
{
    return result;
}
void Calc::clear()
{
    result = 0;
}

// 단위 변환
double Calc::inchToMeter(double inch)
{
    return inch * 0.0254;
}
double Calc::meterToInch(double meter)
{
    return meter / 0.0254;
}
double Calc::mileToKm(double mile)
{
    return mile * 1.60934;
}
double Calc::kmToMile(double km)
{
    return km / 1.60934;
}
double Calc::celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}
double Calc::fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
double Calc::poundToGram(double pound)
{
    return pound * 453.592;
}
double Calc::gramToPound(double gram)
{
    return gram / 453.592;
}
double Calc::kilogramToGram(double kg)
{
    return kg * 1000;
}
double Calc::gramToKilogram(double g)
{
    return g / 1000;
}
double Calc::kilogramToPound(double kg)
{
    return kg * 2.20462;
}
double Calc::poundToKilogram(double pound)
{
    return pound / 2.20462;
}

// 통계 계산
double Calc::average(const std::vector<double>& nums)
{
    double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
    return sum / nums.size();
}
double Calc::standardDeviation(const std::vector<double>& nums)
{
    double mean = average(nums);
    double sq_sum = std::accumulate(nums.begin(), nums.end(), 0.0, [mean](double acc, double num) {
        return acc + (num - mean) * (num - mean);
    });
    return std::sqrt(sq_sum / nums.size());
}
double Calc::median(std::vector<double> nums)
{
    std::sort(nums.begin(), nums.end());
    if (nums.size() % 2 == 0)
        return (nums[nums.size()/2 - 1] + nums[nums.size()/2]) / 2;
    else
        return nums[nums.size()/2];
}
double Calc::max(const std::vector<double>& nums)
{
    return *std::max_element(nums.begin(), nums.end());
}
double Calc::min(const std::vector<double>& nums)
{
    return *std::min_element(nums.begin(), nums.end());
}
