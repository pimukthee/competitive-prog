#include <bits/stdc++.h>

using namespace std;

int sum[1000005];
bool p[1000005];

int main() {
    int q, l, r;
    scanf("%d", &q);

    for (int i = 2; i <= 1000000; ++i) {
        if (!p[i]) {
            for (int j = i + i; j <= 1000000; j += i) {
                p[j] = true;
            }
        }
    }
    for (int i = 2; i <= 1000000; ++i) sum[i] = sum[i - 1] + !p[i];

    while (q--) {
        scanf("%d %d", &l, &r);
        if (l > r) swap(l, r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }

    return 0;
}