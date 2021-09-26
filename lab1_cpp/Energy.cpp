#include "Energy.h"

Energy::Energy()
{
    this->value = 10;
}

Energy::Energy(const Massa& massa)
{
    this->value = massa.get() * C * C;
}

Energy::Energy(double _v) {
    if (_v >= 0) {
        value = _v;
    }
    else
        throw invalid_argument("massa >= 0");
}

Energy::Energy(const Energy& reference)
{
    this->value = reference.value;
}

double Energy::get() const
{
    return value;
}

Energy& Energy::operator=(const Energy& right)
{
    value = right.value;
    return *this;
}

Energy operator+(const Energy& left, const Energy& right)
{
    return Energy(left.get() + right.get());
}

Energy operator-(const Energy& left, const Energy& right)
{
    return Energy(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Energy& obj)
{
    out << obj.get() << "J";
    return out;
}

Energy::operator Massa() const
{
    return Massa(this->value / C / C);
}

Energy::~Energy()
{
}

Energy operator "" J(long double x)
{
    return Energy(x);
}

bool Energy::operator==(const Energy& massa) const noexcept
{
    return this->value == massa.value;
}

std::partial_ordering Energy::operator<=>(const Energy& energy) const noexcept
{
    return value <=> energy.get();
}