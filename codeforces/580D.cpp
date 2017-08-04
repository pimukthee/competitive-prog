#include <bits/stdc++.h>

using namespace std;

int sat[20][20], a[20];
long long dp[1 << 19][20], ans = -1;

int main() {
    int n, m, k, x, y, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[1 << i][i] = a[i];
    }
    while (k--) {
        cin >> x >> y >> c;
        sat[x - 1][y - 1] = c;
    }
    int possible = (1 << n);
    for (int i = 1; i <= possible; ++i) {
        int taken = i, taken_count = 0;
        while (taken > 0) {
            int last = log2(1.0 * (taken & -taken));
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) == 0) {
                    int next_idx = i | (1 << j);
                    dp[next_idx][j] = max(dp[next_idx][j], 1ll*dp[i][last] + sat[last][j] + a[j]);
                }
            }
            ++taken_count;
            taken -= taken & -taken;
        }
        if (taken_count == m) ans = max(ans, *max_element(dp[i], dp[i] + n));
    }

    cout << ans << endl;

    return 0;
}