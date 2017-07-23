#include <bits/stdc++.h>

using namespace std;

int a[300005];

int main() {
    int n;
    long long ans = 0;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) ans += 1ll * abs(i - a[i]);

    printf("%lld\n", ans);

    return 0;
}