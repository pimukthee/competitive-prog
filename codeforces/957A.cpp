#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool ans=false;
    string str;

    cin >> n >> str;

    if (str[0] == str[1]) ans = false;
    for (int i = 1; i < n; ++i) {
        if (str[i] == '?' && (str[i-1] == str[i+1] || str[i-1] == '?')) {
            ans = true;
        } else if (str[i] == str[i-1]) {
             ans = false;
             break;
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
