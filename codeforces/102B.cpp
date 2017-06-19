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
int sum[5];
int main()
{
    string s;
    int j=1,ans = 0;
    cin >> s;
    if(s.size() >= 2) ans = 1;
    for(char i: s)
        sum[0] += i-'0';
    while(sum[j^1] >= 10)
    {
        sum[j] = 0;
        ans ++;
        while(sum[j^1]>0)
        {
            sum[j] += sum[j^1]%10;
            sum[j^1] /= 10;
        }
        j^=1;
    }
    cout << ans;
    return 0;
}
