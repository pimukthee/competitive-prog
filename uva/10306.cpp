#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[45];

int main() {
    int t, m, s;
    cin >> t;
    while (t--) {
        cin >> m >> s;
        vector<vector<int>> dp(400);
        for (int i = 0; i < m; ++i) cin >> arr[i].first >> arr[i].second;
        for (auto &i : dp) i.assign(400, 1e9);

        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            int f = arr[i].first, s = arr[i].second;
            for (int j = f; j <= 300; ++j) {
                for (int k = s; k <= 300; ++k) {
                    dp[j][k] = min(dp[j][k], dp[j-f][k-s] + 1);
                }
            }
        }

        int ans = 1e9;
        for (int i = 0; i <= 300; ++i) {
            for (int j = 0; j <= 300; ++j) {
                if (i*i + j*j == s*s) {
                    ans = min(dp[i][j], ans);
                }
            }
        }

        if (ans == 1e9) {
            cout << "not possible\n";
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
