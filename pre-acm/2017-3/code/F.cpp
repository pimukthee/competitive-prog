#include <bits/stdc++.h>

using namespace std;
    
const double PI = 4.0 * atan(1);

int main() {
    double x, y, z;

    scanf("%lf %lf %lf", &x, &y, &z);
    double a = (180 - ((90 - x) + (90 - y))) * PI / 180.0;
    double r = z / ( 2.0 * sin(a / 2.0));
    
    printf("%.8lf", (a / (2 * PI)) * 2 * PI * r);

    return 0;
}