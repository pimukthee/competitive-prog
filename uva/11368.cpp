#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pi pair<int, int>

bool cmp(pi &a, pi &b) {
    if (a.F != b.F) {
        return a.F < b.F;
    } else {
        return a.S > b.S;
    }
}

bool is_fit(pi &a, pi &b) {
    return a.F < b.F && a.S < b.S;
}

int bsearch(vector<pi> &dolls, pi doll) {
    int left = 0, right = dolls.size()-1, ans = -1;
    while (left <= right) {
        int mid = (left+right) / 2;
        if (is_fit(dolls[mid], doll)) {
            //printf("%d %d <> %d %d\n", dolls[mid].F, dolls[mid].S, doll.F, doll.S);
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int c, n;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        vector <pi> dolls(n);
        vector <pi> dp;
        for (int i = 0; i < n; ++i) scanf("%d %d", &dolls[i].F, &dolls[i].S);

        sort(dolls.begin(), dolls.end(), cmp);

        for (auto i : dolls) {
            if (dp.empty()) {
                dp.push_back(i);
            } else {
                int idx = bsearch(dp, i);
                if (idx == -1) {
                    dp.push_back(i);
                } else {
                    dp[idx] = i;
                }
            }
        }

        printf("%d\n", dp.size());
    }
    return 0;
}



