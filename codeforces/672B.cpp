#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set <char> alp;
    string str;

    cin >> n >> str;

    for (auto c : str) alp.insert(c);
    if (n > 26) cout << -1;
    else cout << n - alp.size() << endl;

    return 0;
}