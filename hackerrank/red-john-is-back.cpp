#include <cstdio>
#include <vector>
using namespace std;
vector <int> p;
bool prime[300005];
int arr[50]={1};
int main()
{
    int T,n;
    for(int i=1; i<=40; i++)
    {
        arr[i]+=arr[i-1];
        if(i>=4)
            arr[i]+=arr[i-4];
    }
    for(int i=2; i<=300000; i++)
    {
        if(!prime[i])
        {
            p.push_back(i);
            for(int j=i+i; j<=300000; j+=i)
                prime[j]=true;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0; p[i]<=arr[n]; i++)
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}
