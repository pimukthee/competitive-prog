#include <cstdio>
#include <vector>
using namespace std;
vector <int> prime;
bool p[5050005];
int sum[5000005];
int numdiv(int n)
{
    int i=0,pf = prime[i],ans=0;
    while(pf*pf<=n)
    {
        while(n%pf==0)
        {
            n/=pf;
            ans++;
        }
        pf = prime[++i];
    }
    if(n!=1) ans++;
    return ans;
}
int main()
{
    for(int i=2; i<=5000000; i++)
    {
        if(!p[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=5000000; j+=i)
                p[j]=true;
        }
    }
    for(int i=2; i<=5000000; i++)
    {
        sum[i]=sum[i-1];
        if(!p[i])
            sum[i]++;
        else
            sum[i]+=numdiv(i);
    }
    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[a]-sum[b]);
    }
    return 0;
}
