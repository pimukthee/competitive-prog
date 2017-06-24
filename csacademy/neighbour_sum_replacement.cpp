#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    a[0] = a[n];
    a[ n + 1] = a[1];
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i - 1] + a[i + 1]);
    return 0;
}
