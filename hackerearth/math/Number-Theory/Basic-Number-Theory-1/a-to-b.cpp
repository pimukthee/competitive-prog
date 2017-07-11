#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int arr[100005];

int p(int n, int k) {
    int d = 1;

    while (k) {
        if (k & 1) d = (1ll * d * n) % mod;
        n = (1ll * n * n) % mod;
        k >>= 1;
    }

    return d;
}

int mod_inverse(int a) {
    return p(a, mod - 2);
}

int main() {
    int n, b = 1, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        b = (1ll * b * arr[i]) % mod;
    }
    scanf("%d", &q);
    while (q--) {
        int com, id, v;
        scanf("%d %d", &com, &id);
        if (com == 0) {
            scanf("%d", &v);
            if (arr[id] == 0) {
                b = 1;
                for (int i = 1; i <= n; ++i) {
                    int k = (i == id ? v : arr[i]);
                    b = (1ll * b * k) % mod;
                }
            } else {
                b = (1ll * ((1ll * b * mod_inverse(arr[id])) % mod) * v) % mod;
            }
            arr[id] = v;
        } else {
            int ans;
            if (arr[id] == 0) {
                ans = 1;
                 for (int i = 1; i <= n; ++i) {
                    int k = (i == id ? 1 : arr[i]);
                    ans = (1ll * ans * k) % mod;
                }
            }
            ans = (1ll * b * mod_inverse(arr[id])) % mod;
            printf("%d\n", ans);
        }
    }

    return 0;
}