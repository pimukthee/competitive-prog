#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, ans = "";

    cin >> str;

    for (auto c : str) {
        if (c == 'h' && ans == "") ans += c;
        else if (c == 'e' && ans == "h") ans += "e";
        else if (c == 'l' && ans == "he") ans += "l";
        else if (c == 'l' && ans == "hel") ans += "l";
        else if (c == 'o' && ans == "hell") ans += "o";
    }

    if (ans == "hello") cout << "YES";
    else cout << "NO";

    return 0;
}