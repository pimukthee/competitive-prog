#include <bits/stdc++.h>

#define MAXN 1000005

using namespace std;

int arr[20];
int sum[MAXN];

bool is_almighty_pandigital_number(int n) {
    memset(arr, 0, sizeof arr);
    int len = log10(n) + 1, digit = 0;
    while (n) {
        arr[n % 10] = 1;
        n /= 10;
    }
    for_each(arr + 1, arr + len + 1, [&digit](int k) {
        digit += k;
    });
    return (digit == len);
}

int main() {
    int t, l, r;
    scanf("%d", &t);
    for (int i = 1; i < MAXN; ++i) sum[i] = sum[i - 1] + is_almighty_pandigital_number(i);

    while (t--) {
        scanf("%d %d", &l, &r);
        if (l > r) swap(l, r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }

    return 0;
}