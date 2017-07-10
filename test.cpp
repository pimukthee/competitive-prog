#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, dp[MAXN], ans;
bool mark[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x - 1)
            mark[x] = true;
    }

    for (int k = 2; k < MAXN; ++k)
    {
        if (mark[k])
            dp[k] = (dp[k] + 1) % MOD;
        for (int j = k + k; j < MAXN && j <= k * k; j += k)
        {
            if (!mark[j])
                continue;
            dp[j] = (dp[j] + 1ll * dp[k] * dp[j / k]) % MOD;
            if (k != j / k)
                dp[j] = (dp[j] + 1ll * dp[k] * dp[j / k]) % MOD;
        }
        ans = (ans + dp[k]) % MOD;
    }

    printf("%d\n", ans);
    return 0;
}