#pragma once
#include <iostream>
#include<compare>

using namespace std;

class Temperature
{
    double value;
public:
    Temperature();
    double get() const;
    Temperature(double _v);
    Temperature(const Temperature& reference);

    Temperature& operator=(const Temperature& right);


    friend ostream& operator<<(ostream& out, const Temperature& obj);

    virtual ~Temperature();
    std::partial_ordering operator<=>(const Temperature&) const noexcept;
    bool operator==(const Temperature& temperature)const noexcept;
};
Temperature operator "" K(long double x);
Temperature operator+(const Temperature& left, const Temperature& right);
Temperature operator-(const Temperature& left, const Temperature& right);