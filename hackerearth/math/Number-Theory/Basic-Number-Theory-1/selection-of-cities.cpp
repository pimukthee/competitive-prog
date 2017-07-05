#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long p(long long n, long long k) {
    long long d = 1;

    while (k) {
        if (k & 1) d = (d * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }

    return d;
}

int main() {
    int t;
    long long n;

    scanf("%d", &t);
    
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", (p(2ll, n) - 1ll + MOD) % MOD);
    }

    return 0;
}