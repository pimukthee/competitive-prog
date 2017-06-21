#include <bits/stdc++.h>

using namespace std;

int w[100005], h[100005], wm, hm;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &w[i], &h[i]);
    wm = *max_element(w, w + n);
    hm = *max_element(h, h + n);
    for (int i = 0; i < n; ++i) ans += (w[i] == wm || h[i] == hm);
    printf("%d", ans);
    return 0;
}
for_each