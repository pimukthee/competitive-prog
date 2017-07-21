#include <bits/stdc++.h>

using namespace std;

int sum[200000], a[200000];

int main() {
    int n, k, m = 1e9, ans;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(i >= k) {
            sum[i] = sum[i - 1] + a[i] - a[i - k];
            if(sum[i] < m) {
                m = sum[i];
                ans = i - k + 1;
            }
        } else {
            sum[i] = sum[i - 1] + a[i];
        }
    }

    printf("%d",ans);

    return 0;
}