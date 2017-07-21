#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;

    cin >> n >> k;

    cout << (2*k - 1 <= n ? 2*k - 1 : 2*k - n - n%2) << endl;
    
    return 0;
}