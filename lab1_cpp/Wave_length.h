#pragma once
#include <iostream>
#include<compare>
#include "Radiation_frequency.h"
#include "Constant.h"
using namespace std;

class Wave_length
{
    double value;
public:
    Wave_length();

    Wave_length(double _v);
    Wave_length(const Wave_length& reference);
    Wave_length(const Radiation_frequency& reference);
    operator Radiation_frequency()const;
    double get() const;
    Wave_length& operator=(const Wave_length& right);


    friend istream& operator>>(istream& in, Wave_length& obj);
    virtual ~Wave_length();
    std::partial_ordering operator<=>(const Wave_length&) const noexcept;
    bool operator==(const Wave_length& wave_length)const noexcept;
};
Wave_length operator "" m(long double x);
Wave_length operator+(const Wave_length& left, const Wave_length& right);
Wave_length operator-(const Wave_length& left, const Wave_length& right);
ostream& operator<<(ostream& out, const Wave_length& obj);