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
int dig[300];
char s[300];
int main()
{
    int prev = 0;
    dig['B']=dig['F'] = dig['P'] = dig['V'] = 1;
    dig['C']=dig['G']=dig['J']=dig['K']=dig['Q']=dig['S']=dig['X']=dig['Z'] = 2;
    dig['D']=dig['T'] = 3;
    dig['L'] = 4;
    dig['M'] = dig['N'] = 5;
    dig['R'] = 6;
    while(scanf(" %s",s)>0)
    {
        for(int i=0; s[i]; i++)
        {
            int k = dig[s[i]];
            if(k>0 && k != prev)
            {
                printf("%d",k);
                prev = k;
            }
            else prev = 0;
        }

        printf("\n");
    }
    return 0;
}
