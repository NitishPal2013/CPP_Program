/**
 * @file
 * @brief Implementaion of [Trapezoidal Rule for finite Integrals]
 * (https://en.wikipedia.org/wiki/Trapezoidal_rule)
 * @details
 * ### Algorithm
 *
 * Input :-
 * 1) a function (func)
 * 2) lower bound and upper bound (a,b)
 * 3) number of intervals (n)
 * 
 * Ouput :- 
 * Approximated area of trapezoid formed by the function (func) and interval (a,b).
 * 
 * Steps:- 
 * 1) Divide the inteval in n subintervals of equal width. The width h = (b-a)/n.
 * 2) Approximate the area with this formula
 *      Area = (func(a) + 2*(func(a + 1*h) + ...  func(a + (n-1)*h)) func(b))*h/2
 * 3) return the Area
 *
 * @author [Nitish Pal] (https://github.com/NitishPal2013)
 */

/**
 * Things required and keep in mind:-
 * input :-
 * 1) a function
 * 2) two values as the range
 *
 * Output :-
 * value of the approximated integration value of the function with given bounds
 *
 * features :-
 * 1) handling values of max size example any doubleing value
 * 2) precision of the output needed to be accurate
 *
 */

#include <cassert>  /// for assert
#include <iostream> /// for IO operations
#include <cmath>    /// for functions to test the algorithm
#include <typeinfo>
using namespace std;

/**
 * @brief trapezoidal_rule()
 * The trapezoidal rule is a numerical integration method that approximates
 * the definite integral of a function by averaging the areas of trapezoids formed under the curve.
 *
 * @param func  the function of which integral is approximated
 * @param b     upper bound
 * @param a     lower bound
 * @param n     number of intervals.
 * @return double
 */

double trapezoidal_rule(double (*func)(double), double a, double b, int n)
{
    double value = 0.0;
    double h = (b - a) / n; // This is the length between two equal intervals
    for (int i = 1; i <= n - 1; i++)
    {
        value += func(a + (i * h));
    }

    value = (func(a) + 2 * value + func(b)) * h / 2;
    return value;
}

/**
 * @brief tests()
 *
 * @return void
 */

void test()
{
    auto func1 = [](double x)
    { return 1 / x; };
    auto func2 = [](double x)
    { return exp(-x); };
    auto func3 = [](double x)
    { return 1 / (1 + x * x); };
    assert((abs(trapezoidal_rule(func1, 1.0, 2.0, 10) - 0.693771) < 1e-6));
    assert((abs(trapezoidal_rule(func2, 0.0, 1.0, 10) - 0.632647) < 1e-6));
    assert((abs(trapezoidal_rule(func3, 0.0, 1.0, 20) - 0.785294) < 1e-6));
    cout << "All Test Cleared!" << endl;
}

int main()
{
    test();
    return 0;
}