#include <bits/stdc++.h>

using namespace std;

long long dp[100005];

int main() {
    const long long mod = 1e9 + 7;
    
    int t, k;

    scanf("%d %d", &t, &k);

    dp[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        dp[i] = (dp[i] + dp[i - 1]) % mod;
        if (i >= k) dp[i] = (dp[i] + dp[i - k]);
    }
    for (int i = 1; i <= 100000; ++i) dp[i] = (dp[i] + dp[i - 1]) % mod;

    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", (dp[b] - dp[a - 1] + mod) % mod);
    }

    return 0;
}