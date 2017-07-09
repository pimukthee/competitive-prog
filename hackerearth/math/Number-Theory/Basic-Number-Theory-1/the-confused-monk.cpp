#include <bits/stdc++.h>

const long long MOD = 1e9 + 7;

using namespace std;

long long p(long long a, long long n) {
    long long d = 1;
    while (n) {
        if (n & 1)
            d = (d * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }

    return d;
}

int main() {
    int n;
    long long a;
    cin >> n >> a;
    long long gcd = a;
    long long f = a;
    while (--n) {
        cin >> a;
        f = (f * a) % MOD;
        gcd = __gcd(a, gcd);
    }

    cout << p(f, gcd);
    
    return 0;
}