#include <bits/stdc++.h>

using namespace std;

int main () {
    int a = 1, b = 1, c = 1, n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int pa = a, pb = b, pc = c;
        a += b;
        b += pa + pc;
        c += pb;
    }
    cout << a + b + c << endl;

    return 0;
}