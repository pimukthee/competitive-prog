#include <bits/stdc++.h>

using namespace std;

int arr[200010];

int main() {
    int n, k;

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    sort(arr+1, arr+n+1);
    if (arr[k] == arr[k+1] || (k == 0 && arr[1] == 1)) {
        printf("-1");
    } else {
        printf("%d", k == 0? arr[1] - 1:arr[k]);
    }

    return 0;
}
