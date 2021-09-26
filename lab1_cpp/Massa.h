#pragma once
#include <iostream>
#include <compare>
#include <stdexcept>
#include "Constant.h"

using namespace std;

class Massa
{
    double value;
public:
    Massa();
    Massa(double _v);
    Massa(const Massa& reference);
  // Massa(const Energy& energy);
    double get() const;
    Massa& operator=(const Massa& right);
    virtual ~Massa();
    std::partial_ordering operator<=>(const Massa&) const noexcept;
    bool operator==(const Massa& massa) const noexcept;
    
};

Massa operator "" kg(long double x);
Massa operator+(const Massa& left, const Massa& right);
Massa operator-(const Massa& left, const Massa& right);
ostream& operator<<(ostream& out, const Massa& obj);