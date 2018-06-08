#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        vi dp;
        dp.assign(3005, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].first, &arr[i].second);

        for (int i = 0; i < n; ++i) {
            int load = arr[i].second, weight = arr[i].first;
            for (int j = weight; j <= 3000; ++j) {
                int remaining_load = min(j-weight, load);
                dp[remaining_load] = max(dp[remaining_load], dp[j] + 1);
            }
            dp[load] = max(dp[load], 1);
        }

        printf("%d\n", *max_element(dp.begin(), dp.end()));
    }
    return 0;
}
