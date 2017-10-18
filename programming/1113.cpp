#include <bits/stdc++.h>

using namespace std;

unordered_map <long long, int> idx;

int main() {
    int n, k, ans = 0;
    long long cur = 0;
    char c;
    scanf("%d %d ", &n, &k);

    idx[0] = 0;
    for (int i = 1; i <= n; ++i) {
        c = getchar();
        cur += (c == 'R' ? 1ll* k : -1);
        if (idx.find(cur) == idx.end()) {
            idx[cur] = i;
        } else {
            ans = max(ans, i - idx[cur]);
        }
    }
    printf("%d", ans);

    return 0;
}
