#include <bits/stdc++.h>

using namespace std;

int lex[200];
string str[100005];

bool cmp(string a, string b) {
    for (int i = 0; a[i] && b[i]; ++i) {
        if (a[i] != b[i]) {
            return lex[a[i]] < lex[b[i]];
        }
    }
    return a.size() < b.size();
}

int main() {
    char k;
    for (int i = 1; i <= 26; ++i) {
        cin >> k;
        lex[k] = i;
        lex[k - 32] = i + 26;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> str[i];

    sort(str, str + n, cmp);
    
    for (int i = 0; i < n; i++) cout << str[i] << endl;

    return 0;
}