#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    int gcd = a;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        gcd = __gcd(gcd, a);
    }

    cout << gcd * n << endl;

    return 0;
}