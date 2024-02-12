#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x - 0.75;
}

double g(double x) {
    return 0.4 * x * (1 - x);
}

double h(double x) {
    return 3.0 * x * (1 - x);
}

double i(double x) {
    return sin(x);
}

unsigned long long approach_fp(double (*F)(double), double x_0, double p) {
    unsigned long long iterations = 0;

    while (abs(p - x_0) > 1e-8) {
        x_0 = F(x_0);
        iterations++;
    }

    return iterations;
}

int main() {
    cout << "F(x) = x^2 - 0.75" << endl;
    cout << approach_fp(&f, 0.2, 0.0) << endl << endl;

    cout << "F(x) = 0.4x(1 - x)" << endl;
    cout << approach_fp(&g, 0.2, 0.0) << endl << endl;

    cout << "F(x) = 3.0x(1 - x)" << endl;
    cout << approach_fp(&h, 0.2, 2.0/3.0) << endl << endl;

    cout << "F(x) = sin(x)" << endl;
    cout << approach_fp(&i, 0.2, 0.0) << endl;

    return 0;
}