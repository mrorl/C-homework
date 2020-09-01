/*
б) Создать класс safe_c_array_t
1. При создании принимает размер и выделяет массив через new
2. При разрушении удаляет выделенный массив
3. Можно получить доступ к значениям через operator[]
4. Умеет копироваться
 */

#include <iostream>
using namespace std;


class safe_c_array_t {
private:

    int *data;

public:

    safe_c_array_t(int Size)
    {
        this->Size = Size;
        data = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            data[i] = i;
        }
        cout << "Constructor" <<endl;
    }


    ~safe_c_array_t()
    {
        cout << "Destructor" << endl;
        delete[] data;
    }

    safe_c_array_t & operator = (const safe_c_array_t & other)
    {
        if (data != other.data) {
            delete [] data;
            Size = other.Size;
            data = new int[Size];
            for (int i = 0; i < Size; i++) {
                data[i] = other.data[i];
            }
        }
        cout << "Assignment operator" << endl;
    }

    safe_c_array_t(const safe_c_array_t & other)
    {
        Size = other.Size;
        data = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            data[i] = other.data[i];
        }
        cout << "Copying constructor" <<endl;
    }


    int &operator[](const int index)
    {
        return data[index];
    }


    friend ostream& operator<<(ostream &os, const safe_c_array_t& a)
    {
        os << a.data;

        return os;
    }

    friend istream& operator>>(istream &is, const safe_c_array_t& a)
    {
        is >> a;

        return is;
    }

    int Size;
};



int main()
{
    safe_c_array_t a(6);

    safe_c_array_t d(a);

    for (int j = 0; j < d.Size; j++) cout << d[j] << endl;

    d = d;

    for (int j = 0; j < d.Size; j++) cout << d[j] << endl;

    safe_c_array_t c(4);

    for (int j = 0; j < c.Size; j++) cout << c[j] << endl;

    c = d;

    for (int j = 0; j < c.Size; j++) cout << c[j] << endl;

    return 0;
}
