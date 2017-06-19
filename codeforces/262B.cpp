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
    int n,k,sum=0,neg=0,temp=0;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
            neg++;
        sum+=a[i];
    }
    for(int i=0; i<neg; i++)
    {
        if(k>0)
            sum -= 2*a[i];
        a[i]*=-1;
        k--;
    }

    if(k>0)
    {

        k%=2;
        if(k==1)temp = -1000000000;
        for(int i=0; k==1&&i<n; i++)
            temp = max(temp,-2*a[i]);
    }
    printf("%d",sum+temp);
    return 0;
}
