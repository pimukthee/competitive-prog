#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    while (n%10 < k) {
        k -= (n%10 + 1);
        n /= 10;
    }

    cout << n-k << endl;

    return 0;
}
