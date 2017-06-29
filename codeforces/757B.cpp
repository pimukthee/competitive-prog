#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x *x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
bool prime[100005];
int arr[100005];
int main()
{
    int n, m, ans = 1, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[k]++;
    }
    for (int i = 2; i <= 100000; i++)
    {
        if (!prime[i])
        {
            m = arr[i];
            for (int j = i + i; j <= 100000; j += i)
            {
                m += arr[j];
                prime[j] = true;
            }
            ans = max(m, ans);
        }
    }
    printf("%d", ans);
    return 0;
}
