#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, cur = 1, l, r, ans = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <=n ; ++i) {
        scanf("%d %d", &l, &r);
        int skip = (l - cur) / x;
        cur += skip * x;
        ans += l - cur + (r- l + 1);
        cur = r + 1;
    }
    printf("%d\n", ans);
    return 0;
}