#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
double a[100005];
int main()
{
    int n,n1,n2;
    scanf("%d%d%d",&n,&n1,&n2);
    int nn1 = n1;
    int nn2 = n2;
    double ans =0;
    for(int i=0; i<n; i++)
        scanf("%lf",&a[i]);
    sort(a,a+n);
    for(int i=n-1; i>=0; i--)
    {
        if(nn1<=0 && nn2 <= 0) break;
        if(n1<=n2&&nn1>0 || nn2 <=0)
        {
            ans += a[i]/n1;
            nn1--;
        }
        else if(n2<=n1&&nn2>0 || nn1 <= 0)
        {
            ans += a[i]/n2;
            nn2 --;
        }
    }
    cout << fixed << setprecision(8) << ans;
    return 0;
}
