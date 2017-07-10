#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 10;
long long dp[MAXN];
bool mem[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x - 1)
            mem[x] = true;
    }

    int ans = 0;
    for (long long k = 2; k < MAXN; ++k) {
        if (!mem[k]) continue;
        dp[k] = (dp[k] + 1) % MOD;
        for (long long j = k + k; j < MAXN && j <= k * k; j += k) {
            if (!mem[j]) continue;
            dp[j] = (dp[j] + 1ll * dp[k] * dp[j / k]) % MOD;
            if (k != j / k) dp[j] = (dp[j] + 1ll * dp[k] * dp[j / k]) % MOD;
        }
        ans = (ans + dp[k]) % MOD;
    }

    printf("%d\n", ans);

    return 0;
}