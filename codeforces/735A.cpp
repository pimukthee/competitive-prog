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
char line[500];
int main()
{
    int n,k,g,t;
    bool ans = false;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        scanf(" %c",&line[i]);
        if(line[i]=='G')
            g = i;
        else if(line[i] == 'T')
            t = i;
    }
    if(t < g)
    {
        while(g-k>=0)
        {
            g-=k;
            if(line[g] == 'T')
                ans = true;
            if(line[g] == '#')
                break;
        }
    }
    else
    {

        while(g+k<n)
        {
            g+=k;
            if(line[g] == 'T')
                ans = true;
            if(line[g] == '#')
                break;
        }
    }
    cout << (ans?"YES":"NO");
    return 0;
}
