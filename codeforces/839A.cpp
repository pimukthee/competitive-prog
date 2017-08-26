#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a, ans = -1, candies = 0;

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n && ans < 0; ++i) {
        scanf("%d", &a);
        candies += a;
        k -= min(8, candies);
        candies -= min(8, candies);
        if (k <= 0) ans = i;
    }

    printf("%d", ans);

    return 0;
}