#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k, i;
    vector <long long> factors;

    cin >> n >> k;

    for (i = 1; i*i < n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    }
    if (i*i == n) factors.push_back(i);
    sort(factors.begin(), factors.end());

    if (k > factors.size()) cout << -1 << endl;
    else cout << factors[k - 1] << endl;

    return 0;
}