/*Надо создать класс safe_long_long_t, который ведет себя ТОЧНО так же как обычный лонг лонг.
1. Конструкторы
2. operator=
3. Помните про модификаторы доступа
4. Арифметические операторы
5. Операторы сравнения
6. operator« для вывода и operator» для ввода */

#include <iostream>
using namespace std;


class safe_long_long_t {

private:

    long long value;

public:

    safe_long_long_t()
    {
        value = 0;
        cout << "Constructor" << endl;
    }

    safe_long_long_t(long long value)
    {
        this->value = value;
        cout << "Constructor" << endl;
    }


    ~safe_long_long_t()
    {
        cout << "Destructor" << endl;
    }

    long long get_value() const {
        return value;
    }

    safe_long_long_t & operator = (const safe_long_long_t & other)
    {
        value = other.value;
        cout << "Assignment operator" << endl;
    }


    safe_long_long_t operator +=(const safe_long_long_t & other)
    {
        value += other.value;
    }

    safe_long_long_t operator -=(const safe_long_long_t & other)
    {
        value -= other.value;
    }

    safe_long_long_t operator *=(const safe_long_long_t & other)
    {
        value *= other.value;
    }

    safe_long_long_t operator /=(const safe_long_long_t & other)
    {
        value /= other.value;
    }

    safe_long_long_t operator %=(const safe_long_long_t & other)
    {
        value %= other.value;
    }


    safe_long_long_t operator--()
    {
        return safe_long_long_t(--value);
    }

    safe_long_long_t operator--(int)
    {
        return safe_long_long_t(value--);
    }

    safe_long_long_t operator++()
    {
        return safe_long_long_t(value++);
    }

    safe_long_long_t operator++(int)
    {
        return safe_long_long_t(value++);
    }


    friend ostream& operator<<(ostream &os, const safe_long_long_t& a)
    {
        os << a.value;

        return os;
    }


    friend istream& operator>>(istream &is, safe_long_long_t& a)
    {
        is >> a.value;

        return is;
    }

};


safe_long_long_t operator+(safe_long_long_t v1, safe_long_long_t v2)
{
    safe_long_long_t temp = v1;
    temp += v2;

    return temp;
}

safe_long_long_t operator-(safe_long_long_t v1, safe_long_long_t v2)
{
    safe_long_long_t temp = v1;
    temp -= v2;

    return temp;
}

safe_long_long_t operator*(safe_long_long_t v1, safe_long_long_t v2)
{
    safe_long_long_t temp = v1;
    temp *= v2;

    return temp;
}

safe_long_long_t operator/(safe_long_long_t v1, safe_long_long_t v2)
{
    safe_long_long_t temp = v1;
    temp /= v2;

    return temp;
}

safe_long_long_t operator%(safe_long_long_t v1, safe_long_long_t v2)
{
    safe_long_long_t temp = v1;
    temp %= v2;

    return temp;
}


bool operator ==(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return v1.get_value() == v2.get_value();
}

bool operator !=(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return !(v1.get_value() == v2.get_value());
}
bool operator >=(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return v1.get_value() >= v2.get_value();
}
bool operator <=(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return v1.get_value() <= v2.get_value();
}
bool operator <(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return !(v1.get_value() >= v2.get_value());
}
bool operator >(const safe_long_long_t &v1, const safe_long_long_t &v2)
{
    return !(v1.get_value() <= v2.get_value());
}


int main()
{
    safe_long_long_t a(32);

    safe_long_long_t c;

    cin >> c;

    safe_long_long_t d = 6 + a;

    cout << a << endl;

    a = c;

    cout << a << endl;

    cout << d << endl;

    bool e = (a <= d);

    cout << e << endl;

    cout << a<< endl;

    a+=10;

    cout << a<< endl;

    return 0;
}
