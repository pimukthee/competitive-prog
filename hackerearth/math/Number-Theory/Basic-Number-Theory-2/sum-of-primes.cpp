#include <bits/stdc++.h>

using namespace std;

bool p[1000010];
long long sum[1000010];

int main() {
    for (int i = 2; i <= 1000000; ++i) {
        sum[i] += sum[i - 1];
        if (!p[i]) {
            sum[i] += 1ll * 1;
            for (int j = i + i; j <= 1000000; j += i) {
                p[j] = true;
            }   
        }
    }

    int n;
    scanf("%d", &n);

    while (n--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }

    return 0;
}