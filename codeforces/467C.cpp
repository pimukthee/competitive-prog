#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    long long a, b, ans = 0;

    cin >> a >> b;

    for (long long m = 1; m < b; ++m) {
        long long lcd = m*b / __gcd(m, b);
        for (long long x = m; x/b / m <= a; x += lcd) {

            if ((x / b) % m == 0 && x/b / m >= 1) {
                ans = (ans + x) % MOD;
            }
        }
    }

    cout << ans;

    return 0;
}