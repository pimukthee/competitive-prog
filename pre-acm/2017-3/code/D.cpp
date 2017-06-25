#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, ans = "";
    char prev = ' ';
    cin >> str;
    for (auto& c : str) {
        if (c != prev) ans += c;
        prev = c;
    }

    cout << ans << endl;

    return 0;
}