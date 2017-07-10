#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    long long lcm, a;
    cin >> t;
    while (t--) {
        cin >> n >> lcm;
        for (int i = 1; i < n; ++i) {
            cin >> a;
            lcm = lcm * a / __gcd(a, lcm);
        }
        
        cout << lcm << endl;
    }

    return 0;
}