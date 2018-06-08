#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int coins[300];

int main() {
    int t, price, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &price);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &coins[i]);

        vector <int> dp;
        dp.assign(20005, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 20000; j >= coins[i]; --j) {
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }

        pair<int, int> ans;
        for (int i = price; i <= 20000; ++i) {
            if (dp[i] != INF) {
                ans.first = i;
                ans.second = dp[i];
                break;
            }
        }

        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
