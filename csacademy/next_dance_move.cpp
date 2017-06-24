#include <bits/stdc++.h>

using namespace std;

int dance[11] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4};

int main() {
    int n;
    cin >> n;
    n = (n - 1) % 10 + 1;
    cout << dance[n];
    return 0;
}