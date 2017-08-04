#include <bits/stdc++.h>

using namespace std;

int dp[5005], ans[5005];

int main() {
    const int M = 107;

    string s;

    cin >> s;

    for (int i = 1; i <= s.size(); ++i) {
        int pre = 0, suf = 0, k = 1;
        for (int j = i; j <= s.size(); ++j) {
            pre = pre*M + s[j-1];
            suf += k * s[j-1];
            k *= M;
            if (pre == suf) {
                dp[j] = dp[(j+i-1)/2] + 1;
                ++ans[dp[j]];
            }
        }
        memset(dp, 0, sizeof dp);
    }
    for (int i = s.size(); i >= 1; --i) ans[i] += ans[i+1];

    for (int i = 1; i <= s.size(); ++i) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}