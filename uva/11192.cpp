#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cstring>
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
char s[200],ans[200];
int main()
{
    int k;
    while(scanf("%d",&k) && k!=0)
    {
        scanf(" %s",s);
        int l = strlen(s);
        k = l/k;
        for(int i=0; i<l; i+=k)
        {
            for(int j=i+k-1,cnt = 0; j>=i; j--,cnt++)
                ans[i+cnt] = s[j];
        }
        for(int i=0; i<l; i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
