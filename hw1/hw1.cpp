#include <iostream>
#include <cmath>

using namespace std;

double f(double n) {
    return -n * log(n);
    // sqrt(n)        | 100 40  1    20
    // - n * n - 0.5  | 100 40 -1    1
    // - n * log(n)   | 100 40 0.001 2
}

int main() {
    double col_num, height, x0, x1;
    col_num = 10;
    x0 = 1;
    x1 = 8;
    cout << "Write down four numbers: " << "\n";
    cin >> col_num >> height >> x0 >> x1;

    double coef;
    if (col_num > x1 - x0) {
        coef = (x1 - x0) / col_num;
    } else {
        coef = col_num / (x1 - x0);
    }

    double min = 0;
    double max = 0;
    double x = x0;
    do {
        if (f(x) < min) {
            min = f(x);
        } else if (f(x) > max) {
            max = f(x);
        }
        x += coef;
    } while (x <= x1);
    double coef2 = (max - min) / height;

    double row = max;
    double col = x0;
    int i, k;
    int j = 1;
    while (row >= min - coef2) {

        cout << j;

        for (i = 0; i <= col_num; i++) {

            if (row < f(col)) {
                if (row > 0) cout << "#";
                if (row < 0) cout << " ";
            } else {
                if (row > 0) cout << " ";
                if (row < 0) cout << "#";
            }
            col += coef;
        }
        if (abs(row) < coef) {
            if (row != 0) {
                cout << endl;
                j++;
                cout << j;
            }

            for (k = 0; k <= col_num; k++) {
                cout << "-";
            }


        }
        row -= coef2;
        if ((min == 0) and (row < 1e-14)) break;
        j++;
        col = x0;
        cout << "\n";

    }

    return 0;

}
