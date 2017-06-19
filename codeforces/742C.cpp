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
int arr[1005];
int in[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        in[arr[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            printf("-1");
            return 0;
        }
    }
    for(int t=1;t<=n; t++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            int des=j;
            for(int k=0; k<2*t; k++)
                des = arr[des];
            if(j==des)
                cnt++;
        }
        if(cnt==n)
        {
            printf("%d",t);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
