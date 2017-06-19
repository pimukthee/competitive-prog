#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi pair<int,int>
using namespace std;
pi a[100005];
int main()
{
    int n,l=0,r=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        l+=a[i].F;
        r+=a[i].S;
    }
    int ma = abs(l-r),ans=0;
    for(int i=1; i<=n; i++)
    {
        int temp = abs((l-a[i].F+a[i].S)-(r-a[i].S+a[i].F));
        if(temp>ma)
        {
            ma = temp;
            ans = i;
        }
    }
    printf("%d",ans);
    return 0;
}
