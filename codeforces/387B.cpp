#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    vector <int> a(3005);
    vector <int> b(3005);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int i = 0, j = 0;
    while (i < n && j < m) {
        i += (a[i] <= b[j]);
        ++j;
    }

    cout << n - i << endl;

    return 0;
}