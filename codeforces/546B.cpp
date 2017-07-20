#include <bits/stdc++.h>

using namespace std;

int coolness[6005];

int main() {
    int n, a, ans = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++coolness[a];
    }
    
    for (int i = 1; i <= 6000; ++i) {
        int k = max(0, coolness[i] - 1);
        ans += k;
        coolness[i + 1] += k;
    }

    cout << ans << endl;

    return 0;
}