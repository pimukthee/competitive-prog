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
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int l=1,r=n,tl=a[1],tr=a[n];
    while(abs(l-r)>1)
    {
        if(tl<=tr)
        {
             l++;
             tl += a[l];
        }
        else
        {
            r--;
            tr += a[r];
        }
      //  printf("%d %d\n",tl,tr);
    }
    if(n==1) printf("1 0");
    else
    printf("%d %d",l,n-r+1);
    return 0;
}
