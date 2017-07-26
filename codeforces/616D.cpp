#include <bits/stdc++.h>

using namespace std;

int mem[1000006], a[500005];

int main() {
    int n, k, cur = 1, unique = 0, max_interval = 0, l, r;

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (mem[a[i]] == 0) ++unique;
        ++mem[a[i]];
        while (unique > k) {
            if (mem[a[cur]] == 1) --unique;
            --mem[a[cur++]];
        }
        if (i - cur + 1 > max_interval) {
            max_interval = i - cur + 1;
            l = cur;
            r = i;
        }
    }

    printf("%d %d\n", l, r);

    return 0;
}