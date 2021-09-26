#include "Wave_length.h"
Wave_length::Wave_length()
{
    this->value = 10;
}
Wave_length::Wave_length(double _v)
{
    if (_v >= 0) {
        value = _v;
    }
    else
        throw new invalid_argument("Wave_length >= 0");
}
Wave_length::Wave_length(const Wave_length& reference)
{
    this->value = reference.value;
}
Wave_length::Wave_length(const Radiation_frequency& reference)
{
    this->value = C / reference.get();
}
Wave_length::operator Radiation_frequency() const
{
    return Radiation_frequency(C / this->value);
}
double Wave_length::get() const
{
    return value;
}
Wave_length& Wave_length::operator=(const Wave_length& right)
{
    value = right.value;
    return *this;
}

Wave_length operator+(const Wave_length& left, const Wave_length& right)
{
    return Wave_length(left.get() + right.get());
}

Wave_length operator-(const Wave_length& left, const Wave_length& right)
{
    return Wave_length(left.get() - right.get());
}




ostream& operator<<(ostream& out, const Wave_length& obj)
{
    out << obj.get();
    return out;
}
istream& operator>>(istream& in, Wave_length& obj)
{
    in >> obj.value;
    return in;
}

Wave_length::~Wave_length()
{
}
Wave_length operator "" m(long double x)
{
    return Wave_length(x);
}

bool Wave_length::operator==(const Wave_length& massa) const noexcept
{
    return this->value == massa.value;
}

std::partial_ordering Wave_length::operator<=>(const Wave_length& wave_length) const noexcept
{
    return value <=> wave_length.get();
}