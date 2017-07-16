#include <bits/stdc++.h>

using namespace std;

int dp[5][100005], n, k;

int find_max(int st) {
    int j = 1, ans = -1;
    for (int i = 1; i <= n; ++i) {
        int num = dp[st ^ 1][i] - dp[st ^ 1][j - 1];
        if (num <= k) ans = max(ans, num + dp[st][i] - dp[st][j - 1]);
        else ++j;
    }

    return ans;
}

int main() {
    char c;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> c;
        dp[0][i] = dp[0][i - 1];
        dp[1][i] = dp[1][i - 1];
        if (c == 'a') ++dp[0][i];
        else ++dp[1][i];
    }

    cout << max(find_max(0), find_max(1)) << endl;

    return 0;
}