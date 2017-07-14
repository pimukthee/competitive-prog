#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, dp[MAXN], ans;
bool mark[MAXN];

int main() {
    int n = 5, ans = n;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) n /= i;
        ans -= ans / i;
    }
    if (n > 1) ans -= ans / n;
    cout << ans;
    return 0;
}