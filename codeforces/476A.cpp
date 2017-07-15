#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans = -1;
    cin >> n >> m;

    for (int i = 0; i <= n && ans == -1; ++i) {
        if ((n - i) % 2 == 0 ) {
            int step = i + (n - i) / 2;
            if (step % m == 0) ans = i + (n - i) / 2;
        }
    }

    cout << ans;

    return 0;
}