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
    long long A, B;
    cin >> A >> B;
    cout << p(A, B);
    return 0;
}