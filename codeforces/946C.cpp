#include <bits/stdc++.h>

using namespace std;

bool was_appear[1101];

int main() {
    int i = 0;
    string str, ans = "";
    char need = 'a';
    cin >> str;

    for (char c : str) {
        if (need <= 'z' && (c == need || (was_appear[need - 1] && c < need))) {
            ans += need;
            was_appear[need] = true;
            ++need;
        } else {
            ans += c;
        }
    }

    if (was_appear['z']) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
