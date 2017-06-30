#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

int main() {
    int sum, limit;
    cin >> sum >> limit;
    for (int i = limit; i >= 1; --i) {
        int n = i & -i;
       // cout << sum << " " << n << endl;
        if (n <= limit && n <= sum) {
            ans.push_back(i);
            sum -= n;
        }
    }
    //cout << sum;
    if (sum != 0) cout << -1;
    else {
        cout << ans.size() << endl;
        for (auto& i : ans) cout << i << " ";
    }
    return 0;
}