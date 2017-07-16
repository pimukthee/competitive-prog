#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long l, r, ans;
    cin >> n;
    while (n--) {
        cin >> l >> r;
        while (l <= r) {
            cout << ans << endl;
            ans = l;
            l |= l + 1;
        }
        cout << ans << endl;
    }

    return 0;
}