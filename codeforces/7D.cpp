#include <bits/stdc++.h>

using namespace std;

const int K = 131;
int dp[5000005];
char s[5000005];

int main() {
    int prefix = 0, suffix = 0, m = 1, ans = 0;

    scanf("%s", s);
    
    for (int i = 0; s[i]; ++i) {
        prefix = prefix*K + s[i];
        suffix += m*s[i];
        m *= K;
        if (prefix == suffix) {
            dp[i+1] = dp[(i+1)/2] + 1;
            ans += dp[i+1];
        }
    }

    cout << ans << endl;

    return 0;
}