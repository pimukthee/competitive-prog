#include <cstdio>
#include <algorithm>
using namespace std;
int arr[200005];
int main()
{
    int n,i,temp=0,temp2=0,nn;
    scanf("%d",&n);
    nn=n;
    for(i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    int minimum = *min_element(arr+1,arr+n+1);
    i = 1;
    while(arr[i++]>minimum) temp++;
    while(arr[n--]>minimum) temp++;
    for( ; i<=n; i++)
    {
        if(arr[i]>minimum)
            temp2++;
        else
        {
            temp=max(temp,temp2);
            temp2=0;
        }
    }
    temp=max(temp,temp2);
    printf("%I64d",1ll*minimum*nn + 1ll*temp);
    return 0;
}
