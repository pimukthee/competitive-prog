#include <bits/stdc++.h>

using namespace std;

int main() {
    int letter, p = 0, a = 0, n;

    cin >> n;

    while (n--) {
        cin >> letter;
        a += (2 - p) * letter;
        p = letter;
    }

    cout << max(a - 1, 0) << endl;

    return 0;
}