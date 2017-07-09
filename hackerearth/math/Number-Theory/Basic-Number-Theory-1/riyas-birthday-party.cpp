#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long m(long long n) {
    return (n % MOD + MOD) % MOD;
}

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lld", &n);
        n %= MOD;
        printf("%lld\n", m(n * m(2 * n - 1)));
    }

    return 0;
}