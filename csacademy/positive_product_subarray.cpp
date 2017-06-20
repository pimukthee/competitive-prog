#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, len = 0, k;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k > 0) {
             len ++;
        } else {
            ans += 1ll* len * (len + 1) / 2;
            len = 0;
        }
    }
    ans += 1ll* len * (len + 1) / 2;
    printf("%lld", ans);
    return 0;
}