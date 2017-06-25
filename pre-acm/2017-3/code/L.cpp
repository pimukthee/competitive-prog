#include <bits/stdc++.h>

using namespace std;

pair <int, int> arr[100005];
vector <int> ans;

int main() {
    int n, x, member, total = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].second, &arr[i].first);
        total += arr[i].first;
        if (arr[i].second == x) member = arr[i].first;
    }

    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; --i) {
        
        if (member > total / 2) break;
        if (arr[i].second != x) {
            ans.push_back(arr[i].second);
            member += arr[i].first;
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto& i : ans) printf("%d ", i);

    return 0;
}