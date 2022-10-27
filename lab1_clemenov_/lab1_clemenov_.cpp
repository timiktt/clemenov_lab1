#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int multiplication_nechet(int n) {
    int rez = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1)
            rez *= i;
    }
    return rez;
}

int multiplication_chet(int n) {
    int rez = 1;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            rez *= i;
    }
    return rez;
}

void my_arccsc(double x) {
    double start = clock();
    double a = 1.0/x;
    double ex = pow(10, -15);
    double rez = 0;
    int i = 1;
    int count = 0;
    cout << "Column\t" << "X\t" << "MY_ARCCSC\t" << "ARCCSC_C++";
    cout << "\t" << "COUNT\t" << "ABSOLUT_POGR\t" << "\t" << "OTNOSIT_POGR\t" << "\t" << "TIME\t" << endl;
    while (a > ex) {
        count++;
        rez += a;
        double end = clock();
        double abs_pogr = fabs(asin(1.0 / x) - rez);
        double otn_pogr = fabs(abs_pogr / (asin(1 / x))) * 100;
        if (count > 1) {
            cout << count - 1 << "\t" << x << "\t" << rez << "\t" << asin(1.0 / x) << "\t";
            cout << count << "\t" << abs_pogr << "\t" << "\t" << otn_pogr << "%";
            cout << "\t" << "\t" << (double)(end - start) / CLOCKS_PER_SEC << "c" << endl;
        }
        i += 2;
        a = (multiplication_nechet(i - 1) / (multiplication_chet(i) * i * pow(x, i)));
    }
    //cout << rez << endl;
}


int main()
{
    double x; 
    cout << "Input |x| > 1 "; 
    cin >> x;
    if (fabs(x) <= 1)
        cout << "Not valid input";
    else
        my_arccsc(fabs(x));
}
