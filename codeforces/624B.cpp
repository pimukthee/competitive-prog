#include <bits/stdc++.h>

using namespace std;

int a[30];

int main() {
    int n;
    long long ans = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    a[n + 1] = a[n] + 1;
    for (int i = n; i >= 1; --i) {
        if (a[i] >= a[i + 1]) a[i] = a[i + 1] - 1;
        ans += 1ll * max(0, a[i]);
    }

    cout << ans << endl;

    return 0;
}