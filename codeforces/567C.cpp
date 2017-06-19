#include <cstdio>
#include <map>
using namespace std;
map <long long,long long> l,r;
int a[200005];
int main()
{
    int n;
    long long k,ans=0;
    scanf("%d%I64d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&a[i]);
        l[a[i]]++;
    }
   // for(int i=n-1; i>=0; i--)
     //   r[a[i]]++;
    for(int i=n-1; i>=0; i--)
    {
        if((k==1||a[i]==0)&&l[a[i]]>=3)
        {
            ans+=l[a[i]]*(l[a[i]]-1)*(l[a[i]]-2)/6;
            l[a[i]] = 0;
        }
        else if(a[i]%k==0&&k!=1&&a[i]!=0)
            ans+=l[a[i]/k]*r[a[i]*k];
        l[a[i]]--;
        r[a[i]]++;
    }
    printf("%I64d",ans);
    return 0;
}
