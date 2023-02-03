#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double raphson(double a, double b, double c, double x) {
    double res = double((a * x) + (b * sin(x)) - c);
    return res;
}

double diffexp(double a, double b, double x) {
    double res = a + (b * cos(x));
    return res;
}

int main() {
    int t;
    double a, b, c, x1, x2;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        x1 = double(c / a);
        x2 = double(x1 - ((raphson(a, b, c, x1)) / (diffexp(a, b, x1))));
        x1 = x2;
        for(int i = 0; i < 100; i++) {
            x2 = double(x1 - ((raphson(a, b, c, x1)) / (diffexp(a, b, x1))));
            x1 = x2;
        }
        printf("%0.06lf\n", x2);
    }
}
