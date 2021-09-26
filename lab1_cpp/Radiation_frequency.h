#pragma once
#include <iostream>
#include<compare>

using namespace std;

class Radiation_frequency
{
    double value;
public:
    Radiation_frequency();

    Radiation_frequency(double _v);
    Radiation_frequency(const Radiation_frequency& reference);
    double get() const;
    Radiation_frequency& operator=(const Radiation_frequency& right);




    virtual ~Radiation_frequency();
    std::partial_ordering operator<=>(const Radiation_frequency&) const noexcept;
    bool operator==(const Radiation_frequency& radiation_frequency)const noexcept;
};
Radiation_frequency operator "" Hz(long double x);
Radiation_frequency operator+(const Radiation_frequency& left, const Radiation_frequency& right);
Radiation_frequency operator-(const Radiation_frequency& left, const Radiation_frequency& right);
ostream& operator<<(ostream& out, const Radiation_frequency& obj);