#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    if(n<=2)
        cout << n;
    else if(n%2 == 0 && n%6 != 0 && n >= 4)
        cout << n*(n-1)*(n-3);
    else if(n%2 == 0 && n%6 == 0 && n >= 4)
        cout << (n-3)*(n-1)*(n-2);
    else
        cout << n*(n-1)*(n-2);
    return 0;
}
