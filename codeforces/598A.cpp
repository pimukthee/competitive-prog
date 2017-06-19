#include <iostream>
using namespace std;
int main()
{
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long p = 0,nn = n;
        while(nn>0)
        {
            nn>>=1;
            p++;
        }
        p--;
        //cout << p << endl;
        cout << n*(n+1ll)/2ll - (1ll << (p+2ll))+2ll <<  endl;
    }
    return 0;
}
