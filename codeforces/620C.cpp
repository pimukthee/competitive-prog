#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > ans;
map <int, int> interval;

int main() {
    int n, k, cur = 1;
    
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        if (interval[k] == ans.size() + 1) {
            ans.push_back(make_pair(cur, i));
            cur = i + 1;
        } else {
            interval[k] = ans.size() + 1;
        }
    }

    if (ans.empty()) printf("-1\n");
    else {
        printf("%d\n", (int)ans.size());
        ans.back().second = n;
        for (auto i : ans) printf("%d %d\n", i.first, i.second);
    }

    return 0;
}