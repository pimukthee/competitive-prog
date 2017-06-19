#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100005],l[100005];
int main()
{
    int n;
    scanf("%d",&n);
    l[1]=1;
    l[2]=2;
    for(int i=1; i<=n; i++)
    {
       scanf("%d",&arr[i]);
       if(i>2)
       {
           if(arr[i]==arr[i-1]+arr[i-2])
                l[i]=l[i-1]+1;
           else
                l[i]=2;
       }
    }
    printf("%d",*max_element(l+1,l+n+1));
    return 0;
}
