#ifndef CALCUL_H
#define CALCUL_H

#include <vector>

class Calc
{
private:
    double result;

public:
    Calc();  // 생성자

    // 계산기 기능
    double add(double num);
    double sub(double num);
    double mul(double num);
    double div(double num);
    double sqrt();
    double pow(double num);
    double fact();
    double sin();
    double cos();
    double tan();
    double log10();
    double ln();
    double rand(double min, double max);
    double pi() const;
    double getRes();
    void clear();

    // 단위 변환
    double inchToMeter(double inch);
    double meterToInch(double meter);
    double mileToKm(double mile);
    double kmToMile(double km);
    double celsiusToFahrenheit(double celsius);
    double fahrenheitToCelsius(double fahrenheit);
    double poundToGram(double pound);
    double gramToPound(double gram);
    double kilogramToGram(double kg);
    double gramToKilogram(double g);
    double kilogramToPound(double kg);
    double poundToKilogram(double pound);

    // 통계 계산
    double average(const std::vector<double>& nums);
    double standardDeviation(const std::vector<double>& nums);
    double median(std::vector<double> nums);
    double max(const std::vector<double>& nums);
    double min(const std::vector<double>& nums);
};

#endif
