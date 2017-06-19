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
vi ans;
int main()
{
    int a,b;
    bool pos = true;
    cin >> a >> b;
    while(a < b && pos)
    {
        ans.pb(b);
        if(b&1)
        {
            if(b%10==1)
                b = (b-1)/10;
            else
                pos = false;
        }
        else
            b >>= 1;
    }
    if(!pos || a!=b) cout << "NO";
    else
    {
        ans.pb(a);
        cout << "YES\n" << ans.size() << endl;
        for(int i=ans.size()-1; i>=0; i--)
            cout << ans[i] << " ";
    }
    return 0;
}
