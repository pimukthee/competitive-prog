#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, n, k;
    scanf("%d", &c);

    while (c--) {
        int ans = 0;
        scanf("%d %d", &n, &k);
        while (n > 0) {
            if (k < (1 << (n-1))) {
                ans <<= 1;
            } else {
                k = (1 << n) - k - 1;
                ans = (ans << 1) + 1;
            }
            --n;
        }

        printf("%d\n", ans);
    }
    return 0;
}
