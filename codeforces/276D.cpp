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
int main()
{
    int a,b,ans=0,l=8,r=12;
    for(int i=l; i<=r; i++)
    {
        for(int j=l; j<=r; j++)
        {
            if((i^j)>ans)
            {
                ans = i^j;
                a = i;
                b = j;
            }
        }
    }
    cout << a << " " << b << endl << ans;
    return 0;
}
 /*LL l,r,cur=1,ans=1;
    cin >> l >> r;
    for( ;cur<=l; cur<<=1);
    ans = min(max(cur-1,l),r);
    cout << ans << endl;
    for( ;cur<=r; cur<<=1)
        ans = cur|ans;
    if(l==r) ans= 0;
    cout << ans;*/
