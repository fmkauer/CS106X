/*
 * File: welcome.cpp
 * -----------------
 * Sample program used to confirm Qt/CS106 install.
 * @author Julie Zelenski
 * #version 2023/09
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "gmath.h"
#include <complex>
#include <string>

using namespace std;
using namespace std::complex_literals;

string prettyComplex(complex<double> z);
void quadratic_solver(double a, double b, double c, complex<double>& x1, complex<double>& x2);

int main()
{
    bool key = true;
    while (key) {
        cout << "Quadratic Equation, given the formula: ax^2 + bx + c = 0" << endl;
        const double a = getReal("The 'a' value for the quadratic: ");
        const double b = getReal("The 'b' value for the quadratic: ");
        const double c = getReal("The 'c' value for the quadratic: ");

        if (a == 0) {
            if (b == 0) {
                cout << "The formula is zero" << endl;
            }
            else {
                cout << "The root is " << -c/b << endl;
            }
            key = getYesOrNo("Do you want to continue? (y/n):");
            continue;
        }

        complex<double> root1, root2;
        quadratic_solver(a, b, c, root1, root2);
        cout << "Root 1 is " << prettyComplex(root1) << " and root 2 is " << prettyComplex(root2) << endl;
        cout << endl;
        key = getYesOrNo("Do you want to continue? (y/n):");
    }
    return 0;
}

void quadratic_solver(const double a, const double b, const double c, complex<double>& x1, complex<double>& x2) {
    const double delta = (b * b - 4 * a * c);
    if (delta == 0) {
        x1 = x2 = - b / (2 * a);
        return;
    } else if (delta < 0) {
        const complex<double> new_delta = sqrt(abs(delta)) * 1i;
        x1 = (-b + new_delta) / (2 * a);
        x2 = (-b - new_delta) / (2 * a);
        return;
    }
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
}

string prettyComplex(const complex<double> z) {
    if (abs(z) == 0) {
        return "0";
    }
    if (z.imag() == 0) {
        return to_string(z.real());
    }
    if (z.real() == 0) {
        return to_string(z.imag()) + 'i';
    }
    return to_string(z.real()) + ' ' + to_string(z.imag()) + 'i';
}