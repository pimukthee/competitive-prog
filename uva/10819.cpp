#include <bits/stdc++.h>

using namespace std;

int dp[200][20000];

int main() {
    int n, m;

    while (scanf("%d %d", &m, &n) > 0) {
        vector <pair<int, int>> items(n+1);
        if (m > 1800) m += 200;
        for (int i = 1; i <= n; ++i) scanf("%d %d", &items[i].first, &items[i].second);
        for (int i = 0; i <= n; ++i) dp[i][0] = 0;
        for (int i = 0; i <= m; ++i) dp[0][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j < items[i].first) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], items[i].second + dp[i-1][j-items[i].first]);
                }
            }
        }
        int ans;
        if (m > 2000 && m <= 2200 && (dp[n][2000] == dp[n][m])) {
            ans = dp[n][m-200];
        } else {
            ans = dp[n][m];
        }

        printf("%d\n", ans);

    }
    return 0;
}
