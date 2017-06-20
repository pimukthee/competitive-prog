#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str, ans = "";
    cin >> n;
    while (n--) {
        cin >> str;
        ans+=*min_element(str.begin(), str.end());
    }
    sort(ans.begin(), ans.end());
    cout << ans;

    return 0;
}