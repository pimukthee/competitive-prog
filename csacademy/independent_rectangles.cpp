#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    vector <pair <int, int> > rec(n);
    for (int i = 0; i < n; i++) scanf("%d %d", &rec[i].first, &rec[i].second);
    sort(rec.begin(), rec.end(), cmp);
    pair <int, int> m(-1, -1);
    for (auto& i: rec) {
        if (i.second >= m.second) {
            ans++;
            m = i;
        }
    }

    printf("%d", ans);
    return 0;
}
