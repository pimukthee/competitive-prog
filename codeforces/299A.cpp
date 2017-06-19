#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
int arr[100005];
int main()
{
    int n,ans;
    scanf("%d%d",&n,&arr[0]);
    ans = arr[0];
    for(int i=1; i<n; i++)
    {
        scanf("%d",&arr[i]);
        ans = __gcd(ans,arr[i]);
    }
    sort(arr,arr+n);
    if(binary_search(arr,arr+n,ans))
        printf("%d",ans);
    else
        printf("-1");
    return 0;
}
