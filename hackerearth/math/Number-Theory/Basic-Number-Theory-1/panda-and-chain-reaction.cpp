#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e6 + 3;

long long fac[1000005] = {1};

int main() {
    for (int i = 1; i <= 1000002; ++i) fac[i] = (fac[i - 1] * i) % MOD;

    int T;
    long long n , x;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld %lld", &n, &x);
        if (x >= MOD) printf("0\n");
        else printf("%lld\n", (fac[n] * x) % MOD);
    }    
    
    return 0;
}