#include <bits/stdc++.h>

using namespace std;

int l[100005], r[100005], a[100005];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i) l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);
    for (int i = n; i >= 1; --i) r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1 : 1);
    int ans = max(*max_element(l + 1, l + n + 1), *max_element(r + 1, r + n + 1)) + 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i + 1] - a[i - 1] > 1) {
            ans = max(ans, l[i - 1] + r[i + 1] + 1);
        }
    }

    printf("%d\n", min(ans, n));

    return 0;
}