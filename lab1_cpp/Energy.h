#pragma once
#include <iostream>
#include <compare>
#include "Constant.h"
#include "Massa.h"


using namespace std;

class Energy
{
    double value;
public:
    Energy();
    Energy(const Energy& reference);
    Energy(const Massa &massa);
    Energy(double _v);

    Energy& operator=(const Energy& right);

    double get() const;

    operator Massa() const;
    virtual ~Energy();
    std::partial_ordering operator<=>(const Energy&) const noexcept;
    bool operator==(const Energy& energy) const noexcept;
};

Energy operator "" J(long double x);
Energy operator+(const Energy& left, const Energy& right);

Energy operator-(const Energy& left, const Energy& right);

ostream& operator<<(ostream& out, const Energy& obj);