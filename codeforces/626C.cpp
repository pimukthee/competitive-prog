#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a = 0, b = 0, c = 0;

    cin >> n >> m;

    for (int i = 2; i <= 10000000; ++i) {
        if (i % 2 == 0) ++a;
        if (i % 3 == 0) ++b;
        if (i % 6 == 0) ++c;
        if (a + b - c >= n + m && b >= m && a >= n) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}