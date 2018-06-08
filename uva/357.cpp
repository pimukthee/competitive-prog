#include <bits/stdc++.h>

using namespace std;

long long dp[40000];

int main() {
    int n;
    dp[0] = 1ll;
    int coins[] = {1, 5, 10, 25, 50};
    for (int i = 0; i < 5; ++i) {
        for (int j = coins[i]; j <= 30000; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }
    while (scanf("%d", &n) > 0) {
        if (dp[n] == 1) {
            printf("There is only %lld way to produce %d cents change.\n", dp[n], n);
        } else {
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
        }
    }
    return 0;
}
