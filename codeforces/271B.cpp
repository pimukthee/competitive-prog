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
vi p;
int a[505][505];
bool prime[1000000];
int main()
{
    prime[1] = true;
    for(int i=2; i<1000000; i++)
    {
        if(!prime[i])
        {
            p.pb(i);
            for(int j=i+i; j<1000000; j+=i)
                prime[j] = true;
        }
    }
    int n,m,temp,ans=1000000000;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    for(int i=0; i<n; i++)
    {
        temp = 0;
        for(int j=0; j<m; j++)
            if(prime[a[i][j]])
                temp+=(*upper_bound(p.begin(),p.end(),a[i][j]))-a[i][j];
        ans = min(ans,temp);
    }
    for(int i=0; i<m; i++)
    {
        temp = 0;
        for(int j=0; j<n; j++)
            if(prime[a[j][i]])
                temp+=(*upper_bound(p.begin(),p.end(),a[j][i]))-a[j][i];
        ans = min(temp,ans);
    }
    printf("%d",ans);
    return 0;
}
