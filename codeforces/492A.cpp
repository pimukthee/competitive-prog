#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, ans = 0, cube = 0;
    cin >> n;
    for (i = 1; ans <= n; ++i) {
        cube += i;
        ans += cube;
    }
    cout << i - 2 << endl;
    return 0;
}