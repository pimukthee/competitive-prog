#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, i;
    vector <int> factors;

    cin >> n >> k;

    for (i = 2; i*i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);

    if (k > factors.size()) cout << -1 << endl;
    else {
        int pro = 1;
        for (i = 0; i < k - 1; ++i) cout << factors[i] << " ";
        for (; i < factors.size(); ++i) pro *= factors[i];
        cout << pro << endl;
    }
    
    return 0;
}