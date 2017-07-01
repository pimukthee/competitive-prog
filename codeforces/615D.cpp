#include <bits/stdc++.h>

const long long mod = 1e9 + 7;
const long long mod2 = (mod - 1) * 2;
using namespace std;

int cnt[200005];

long long p(long long n, long long k) {
    long long d = 1;
    while(k > 0){
        if(k & 1)
            d = (d * n) % mod;
        n = (n * n) % mod;
      k >>= 1;
    }
    
    return d;
}

int main() {
    int m;

    scanf("%d", &m);
    while (m--) {
        int p;
        scanf("%d", &p);
        cnt[p]++;
    }
    
    long long number_of_factor = 1, ans = 1;
    
    for (long long i = 0; i <= 200000; ++i) number_of_factor = (number_of_factor * (cnt[i] + 1ll)) % mod2;
    for (long long i = 2; i <= 200000; ++i) {
        if (cnt[i] > 0) 
            ans = ans * p(i, (number_of_factor * cnt[i] % mod2) >> 1) % mod;
    }

    printf("%lld\n", ans);

    return 0;
}