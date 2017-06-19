#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double n ;
    cin >> n;
    double a = (ceil(n/2.0)*ceil(n/2.0)), b = floor(n/2)*floor(n/2);//cout << a;
    if((a+b)-2.0*floor((a+b)/2.0)==1)
        cout << 1;
    else
        cout << 2;
}
