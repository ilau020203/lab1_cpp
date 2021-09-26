#include "Radiation_frequency.h"

Radiation_frequency::Radiation_frequency()
{
    this->value = 10;
}
Radiation_frequency::Radiation_frequency(double _v)
{
    if (_v >= 0) {
        value = _v;
    }
    else
        throw new invalid_argument("Radiation_frequency >= 0");
}
double Radiation_frequency::get() const
{
    return value;
}

Radiation_frequency operator+(const Radiation_frequency& left, const Radiation_frequency& right)
{
    return Radiation_frequency(left.get() + right.get());
}

Radiation_frequency operator-(const Radiation_frequency& left, const Radiation_frequency& right)
{
    return Radiation_frequency(left.get() - right.get());
}

Radiation_frequency::Radiation_frequency(const Radiation_frequency& reference)
{
    this->value = reference.value;
}
Radiation_frequency& Radiation_frequency::operator=(const Radiation_frequency& right)
{
    value = right.value;
    return *this;
}

ostream& operator<<(ostream& out, const Radiation_frequency& obj)
{
    out << obj.get() << "Hz";
    return out;
}
Radiation_frequency::~Radiation_frequency()
{
    
}
Radiation_frequency operator "" Hz(long double x)
{
    return Radiation_frequency(x);
}

bool Radiation_frequency::operator==(const Radiation_frequency& massa) const noexcept
{
    return this->value == massa.value;
}

std::partial_ordering Radiation_frequency::operator<=>(const Radiation_frequency& Radiation_frequency) const noexcept
{
    return value <=> Radiation_frequency.get();
}