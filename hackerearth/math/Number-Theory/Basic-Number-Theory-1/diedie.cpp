#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long p(long long n, long long k) {
    long long d = 1;

    while (k) {
        if (k & 1) d = (d * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }

    return d;
}

long long mod_inverse(long long a) {
    return p(a, mod - 2);
}

int main() {
    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (mod_inverse(p(2, n)) * 2) % mod << endl;
    }

    return 0;
}