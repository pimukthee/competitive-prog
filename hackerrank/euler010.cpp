#include <iostream>
using namespace std;
bool prime[1000005];
long long sum[1000005];
int main()
{
    prime[1]=true;
    for(int i=2; i<=1000000; i++)
    {
        if(!prime[i])
            for(int j=i+i; j<=1000000; j+=i)
                prime[j]=true;
    }
    for(int i=1; i<=1000000; i++)
    {
        sum[i]=sum[i-1];
        if(!prime[i])
            sum[i]+=i;
    }
    int T,N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << sum[N] << endl;
    }
    return 0;
}
