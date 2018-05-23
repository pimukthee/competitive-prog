#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str;

    cin >> n >> str;

    int zero = count(str.begin(), str.end(), '0');
    if (zero < n) cout << 1;
    while (zero--) cout << 0;


    return 0;
}
