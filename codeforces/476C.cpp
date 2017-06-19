#include <iostream>
long long mod = 1000000007;
using namespace std;
int main()
{
    long long a,b;
    cin >> a >> b;
    long long B = (b*(b-1)/2) % mod ;
    long long A1 = (a*(a+1)/2) % mod ;
    long long A = (A1*b+a) % mod ;
    long long ans = (A*B) % mod ;
    cout << ans;
    return 0;
}
