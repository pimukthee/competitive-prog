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

int a[200005];

int main()
{
    int n, m, b;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        int idx = upper_bound(a, a + n, b) - a;
        printf("%d ", idx);
    }

    return 0;
}
