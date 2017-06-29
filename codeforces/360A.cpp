#include <bits/stdc++.h>

using namespace std;

int arr[5005];
int add[5005];
int t[5005], l[5005], r[5005], d[5005];

int main() {
    int n, m;
    bool ans = true;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) arr[i] = 1000000000;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &t[i], &l[i], &r[i], &d[i]);
        if (t[i] == 1) for (int j = l[i]; j <= r[i]; ++j) add[j] += d[i];
        else for (int j = l[i]; j <= r[i]; ++j) arr[j] = min(arr[j], d[i] - add[j]);
    }
    for (int i = 0; i < m && ans; ++i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j) arr[j] += d[i];
        } else {
            if (*max_element(arr + l[i] , arr + r[i] + 1) != d[i]) ans = false;
        }
    }

    if (ans) {
        printf("YES\n");
        for (int i = 1; i <= n; ++i) printf("%d ", arr[i] - add[i]);
    } else {
        printf("NO");
    }
    return 0;
}