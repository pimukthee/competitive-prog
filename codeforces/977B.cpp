#include <bits/stdc++.h>

using namespace std;

map <string, int> cnt;

int main() {
    int n, m = 0;
    string str, c="", ans;
    cin >> n >> str;

    for (int i = 1; str[i]; ++i) {
        c += str[i-1];
        c += str[i];
        ++cnt[c];
        if (cnt[c] > m) {
            m = cnt[c];
            ans = c;
        }
        c = "";
    }

    cout << ans;

    return 0;
}
