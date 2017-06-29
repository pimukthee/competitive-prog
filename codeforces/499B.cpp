#include <bits/stdc++.h>

using namespace std;

map <string, pair<string, int> > words;

int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        words[a].first = b;
        words[a].second = 1;
        words[b].first = a;
        words[b].second = 2;
    }
    while (n--) {
        cin >> a;
        string another_word = words[a].first;
        if (a.size() < another_word.size()) cout << a;
        else if (a.size() > another_word.size()) cout << another_word;
        else cout << (words[a].second == 1 ? a : another_word);
        cout << " ";
    }

    return 0;
}