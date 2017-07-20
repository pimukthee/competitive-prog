#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1) {
        if (a.back() == 0) cout << "UP";
        else if (a.back() == 15) cout << "DOWN";
        else cout << -1;
    } else if (a.back() == 15 || a[n - 1] < a[n - 2]){
        cout << "DOWN";
    } else if (a.back() == 0 || a[n - 1] > a[n - 2]) {
        cout << "UP";
    }

    return 0;
}