#include <bits/stdc++.h>

using namespace std;

int cnt[100010] = {1}, arr[100010];

int main() {
    int n, c, j = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]];
    }

    for (int i = 0; i < n; ++i) {
        while (cnt[j]) ++j;
        if (cnt[arr[i]] > 1 || arr[i] > n) {
            --cnt[arr[i]];
            arr[i] = j;
            ++j;
        }
    }

    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);

    return 0;
}
