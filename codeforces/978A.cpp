#include <bits/stdc++.h>

using namespace std;

vector <int> ans;
bool is_appeared[5000];
int arr[1010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    for (int i = n-1; i >= 0; --i) {
        if (!is_appeared[arr[i]]) {
            ans.push_back(arr[i]);
        }

        is_appeared[arr[i]] = true;
    }

    printf("%d\n", ans.size());
    reverse(ans.begin(), ans.end());
    for (int i : ans) printf("%d ", i);

    return 0;
}
