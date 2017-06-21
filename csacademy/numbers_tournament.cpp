#include <bits/stdc++.h>

using namespace std;

int arr[105][105], n;
pair <int, int> ans[105];

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

pair <int, int> find_bound(int i, int j) {
    int high = -1, low = -1;
    for (int it = 0; it < n; ++it) {
        if (binary_search(arr[j], arr[j] + n, arr[i][it])) {
            high = arr[i][it];
            if (low == -1) {
                low = arr[i][it];
            }
        }
    }
    return make_pair(low, high);
}

pair <int, int> start_game(int i, int j, pair <int,int> interval) {
    int scorei = 0, scorej = 0;
    for (int it = 0; it < n; ++it) {
        scorei += (arr[i][it] < interval.first || arr[i][it] > interval.second);
        scorej += (arr[j][it] < interval.first || arr[j][it] > interval.second);
    }
    return make_pair(scorei, scorej);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
        sort(arr[i], arr[i] + n);
    }

    for (int i = 1; i <= n; ++i) {
        ans[i].second = i;
        for (int j = i + 1; j <= n; ++j) {
            auto bound = find_bound(i, j);
            auto score = start_game(i, j, bound);
            if (score.first > score.second) {
                ans[i].first += 2;
            } else if (score.first == score.second) {
                ans[i].first++;
                ans[j].first++;
            } else {
                ans[j].first += 2;
            }
        }
    }

    sort(ans + 1, ans + n + 1, cmp);

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i].second);
    }

    return 0;
}

map