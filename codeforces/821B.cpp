#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, b;
    long long ans = 0;
    
    cin >> m >> b;
    for (long long y = b; y >= 0; --y) {
        long long x = -m * (y - b);
        ans = max(ans, 1ll * (x + 1) * (y * (y + 1) + x * (y + 1)) / 2ll);
    }

    cout << ans;

    return 0;
}