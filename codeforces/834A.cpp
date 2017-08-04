#include <bits/stdc++.h>

using namespace std;

int k[120];

int main() {
    char a, b;
    int n;
    k['<'] = 1;
    k['^'] = 2;
    k['>'] = 3;
    cin >> a >> b >> n;
    n %= 4;
    a = k[a];
    b = k[b];
    int cw = (a + n) % 4, ccw = ((a - n) + 4) % 4;
    if (cw == b && ccw == b) {
        cout << "undefined\n";
    } else {
        if (cw == b) {
            cout << "cw\n";
        } else {
            cout << "ccw\n";
        }
    }
    return 0;
}