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
    string s;
    int k;
    cin >> s >> k;
    for(int i=0; i<s.size(); i++)
    {
        int m=i;
        for(int j=i; j<s.size(); j++)
            if(s[j]>s[m]&&j-i<=k) m=j;
        for(int j=m; j>i; j--)
            swap(s[j],s[j-1]);
        k-=m-i;
    }
    cout<<s;
    return 0;
}
