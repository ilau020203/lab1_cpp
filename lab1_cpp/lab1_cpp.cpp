#include <iostream>
#include <compare>
#include "Massa.h"
#include "Radiation_frequency.h"
#include "Temperature.h"
#include "Wave_length.h"
#include "Energy.h"

/*Классы физических величин: масса, энергия, длина волны, частота излучения,
температура, мощность излучения.
Определить для них операторы сложения (+) и вычитания (-) с учетом
физического смысла.
Для каждого класса определить литералы для обозначения размерности:
масса – kg, энергия – J, длина волны – m, частота излучения – Hz,
температура – K, мощность излучения – W.
Для массы и энергии определить взаимнооднозначные операторы преобразования
по формуле E=mc2
, также определить операторы преобразования энергии к
частоте, и частоты к длине волны
*/

using namespace std;


int main()
{
    cout << "Hello World!\n";
    Massa m1, m2;
    m1 = 1;
    m2 = 1;
    Massa m3 = m1 + m2;
    cout << m1 << "+" << m2 << "=" << m3 << "\n";
    cout << (m1 != m2) << endl;
    cout << 10.0kg;
    double c = 300000000.0;
    cout << m1.get();
    Wave_length q;
    cin >> q;
    cout << q;
    m1 = 3;
    cout << (Energy)m1 << endl;
    Energy en = 34354553;
    cout << (Massa)en << endl;

    cout << (Wave_length)34.5Hz << endl;
    cout << (Radiation_frequency)34.5m << endl;


}