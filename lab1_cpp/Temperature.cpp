#include "Temperature.h"

Temperature::Temperature()
{
    this->value = 10;
}
Temperature::Temperature(double _v)
{
    if (_v >= 0) {
        value = _v;
    }
    else
        throw new invalid_argument("Temperature >= 0");
}
Temperature::Temperature(const Temperature& reference)
{
    this->value = reference.value;
}
Temperature& Temperature::operator=(const Temperature& right)
{
    value = right.value;
    return *this;
}
double Temperature::get() const
{
    return value;
}

Temperature operator+(const Temperature& left, const Temperature& right)
{
    return Temperature(left.get() + right.get());
}

Temperature operator-(const Temperature& left, const Temperature& right)
{
    return Temperature(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Temperature& obj)
{
    out << obj.value << "T";
    return out;
}
Temperature::~Temperature()
{
}

Temperature operator "" K(long double x)
{
    return Temperature(x);
}

bool Temperature::operator==(const Temperature& massa) const noexcept
{
    return this->value == massa.value;
}

std::partial_ordering Temperature::operator<=>(const Temperature& temperature) const noexcept
{
    return value <=> temperature.get();
}