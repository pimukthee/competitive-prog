#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,me,a,gcd;
    cin >> n >> a;
    gcd = me = a;
    for(int i=1; i<n; i++)
    {
        cin >> a;
        me = max(me,a);
        gcd = __gcd(gcd,a);
    }
    if((me/gcd-n)&1)
        cout << "Alice";
    else
        cout << "Bob";
    return 0;
}
