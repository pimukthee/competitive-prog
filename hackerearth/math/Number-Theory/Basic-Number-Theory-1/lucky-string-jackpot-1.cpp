#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        long long ans = 0;
        long long prev = 0, cum = 0;
        for (long long i = 2; cum < n; i *= 2) {
            ans ++;
            prev = cum;
            cum += ans * i;
        }

        printf("%lld\n", max(min(n - prev, 2 * ans - 1), 2 * (ans - 1) - 1));
    }

    return 0;
}