#include <iostream>
#define mod 1000003
using namespace std;
int unary[100];
long long power(long long n,long long k)
{
    long long d = 1;
    while(k>0)
    {
        if(k&1)
            d = (d*n)%mod;
        n=(n*n)%mod;
        k >>=1;
    }
    return d;
}
int main()
{
    string P;
    unary['>']=8;
    unary['<']=9;
    unary['+']=10;
    unary['-']=11;
    unary['.']=12;
    unary[',']=13;
    unary['[']=14;
    unary[']']=15;
    cin >> P;
    int s = P.length(),p = 0;
    long long ans =0;
    for(int i = s-1; i>=0; i--)
    {
        ans=(ans+(unary[P[i]]*power(2ll,1ll*p))%mod)%mod;
        p+=4;
    }
    cout << ans;
    return 0;
}
