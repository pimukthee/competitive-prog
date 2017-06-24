#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
#define EPS 1e-7
using namespace std;
double func(double mid)
{
    return mid*mid-3*mid+2;
}
double bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
        cout << "You have not assumed right a and b\n";
    else
    {
        double c = a;
        while ((b-a) >= EPS)
        {
            c = (a+b)/2.0;
            if (fabs(func(c)) <= EPS)
                return c;
            else if (func(c)*func(a) < 0)
                b = c;
            else
                a = c;
        }
    }
}

int main()
{
    cout << bisection(0.3,1.9);
    return 0;
}
