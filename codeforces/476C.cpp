#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    long long a, b;

    cin >> a >> b;

    long long sb = (b*(b - 1) / 2) % MOD;
    long long sa = (a*(a + 1) / 2) % MOD;

    cout << ((((b * sa) % MOD + a) % MOD) * sb ) % MOD << endl;

    return 0;
}
