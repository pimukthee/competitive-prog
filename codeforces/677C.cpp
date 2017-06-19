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
int nullbit(int val)
{
    int bit=0;
    while(val>0)
    {
        bit++;
        val -= val & (-val);
    }
   // cout << bit << en
    return pow(3,6-bit);
}
int main()
{
    string s;
    long long ans=1;
    int val;
    cin >> s;
    for(char c:s)
    {
        if(c == '-') val = 61;
        else if(c== '_') val = 63;
        else if(c >= 'a') val = (c-'a')+36;
        else if(c>='A') val = (c-'A')+10;
        else val = c-'0';
        ans = (ans*nullbit(val))%1000000007;
    }
    cout << ans;
    return 0;
}
