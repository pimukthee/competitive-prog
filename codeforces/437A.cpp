#include <bits/stdc++.h>

using namespace std;

string str[10];
vector <int> ans;

int main() {
    for (int i = 0; i < 4; ++i) cin >> str[i];

    for (int i = 0; i < 4; ++i) {
        int cnt = 0, cnt1 = 0;
        for (int j = 0; j < 4; ++j) {
            cnt += ((i != j) && ((str[i].size() - 2) * 2 <= (str[j].size() - 2)));
            cnt1 += ((i != j) && ((str[i].size() - 2) >= 2 * (str[j].size() - 2)));
        }
        if (cnt == 3 || cnt1 == 3) ans.push_back(i);
    }

    //cout << ans.size() << endl;
    if (ans.size() == 1) cout << (char)(ans[0] + 'A');
    else cout << 'C';

    return 0;
}