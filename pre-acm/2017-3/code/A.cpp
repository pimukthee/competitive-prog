#include <bits/stdc++.h>

using namespace std;

int ans;

void cnt(bool i) {
    ans += i;
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    vector <bool> pos(n);

    while (m--) {
        cin >> a >> b;
        for (int i = a; i <= b; ++i) pos[i] = true;
    }
    for_each (pos.begin(), pos.end(), cnt);
    cout << ans;
    return 0;
}