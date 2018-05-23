#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans =0;
    string str;

    cin >> n >> str;

    for (int i = 0; i < str.size() - 2; ++i) {
        if (str[i] == 'x' && str[i+1] == 'x' && str[i+2] == 'x') {
            ++ans;
        }
    }

    cout << ans;

    return 0;
}
