#include "Massa.h"
#include"Massa.h"

Massa::Massa()
{
    value = 0;
}

Massa::Massa(double _v)
{
    if (_v >= 0) {
        value = _v;
    }
    else
        throw new invalid_argument("massa >= 0");
}

Massa::Massa(const Massa& reference)
{
    this->value = reference.value;
}


double Massa::get() const
{
    return value;
}

Massa& Massa::operator=(const Massa& right)
{
    value = right.value;
    return *this;
}

Massa operator+(const Massa& left, const Massa& right)
{
    return Massa(left.get() + right.get());
}

Massa operator-(const Massa& left, const Massa& right)
{
    return Massa(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Massa& obj)
{
    out << obj.get() << "kg";
    return out;
}

Massa::~Massa()
{

}


Massa operator "" kg(long double x)
{
    return Massa(x);
}

bool Massa::operator==(const Massa& massa) const noexcept
{
    return this->value == massa.value;
}


std::partial_ordering Massa::operator<=>(const Massa& massa) const noexcept
{
    return value <=> massa.get();
}
