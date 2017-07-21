#include <bits/stdc++.h>

using namespace std;

int main() {
    int k = 0;
    string str;

    cin >> str;

    for(auto c : str) {
        k = k*10 + (c-'0');
        k = (k-1) % 4 + 1;
    }

    if (k == 4 || k == 0) cout << 4 << endl;
    else cout << 0 << endl;

    return 0;
}