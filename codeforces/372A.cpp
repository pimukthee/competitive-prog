#include <cstdio>
#include <algorithm>
using namespace std;
int isValid[100005],cnt[100005],inValid=0,removed[100005];
void update(int i, int k)
{
          for( ; i <=100002 ; i += ( i & ( -i ) ) ) removed[i] += k;
}
int Getsum(int a, int b)
{
          if( a != 0 ) return Getsum(0, b) - Getsum(0, a-1);
          int re = 0;
          for( ; b > 0 ; b -= ( b & ( -b ) ) )  re += removed[ b ];
          return re;
}
int main()
{
    int n,ans=0,a;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i=100000; i>=1; i--)
    {
        isValid[i]=isValid[i+1];
        if(cnt[i])
            isValid[i]+=cnt[i];
    }
    for(int i=50000; i>=1; i--)
    {
        inValid=Getsum(i*2,100000);
        if(isValid[i*2]-inValid>0)
        {
            int k = min(isValid[i*2],cnt[i]);
            ans+=k;
            update(i,k);
            update(i*2,k);
        }
    }
    printf("%d",n-ans);
    return 0;
}
