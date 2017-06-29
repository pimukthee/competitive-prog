#include <bits/stdc++.h>

using namespace std;

long long linear(int a, int b,int c, int x, int y) {
    return 1ll * a * x + 1ll * b * y + 1ll * c;
}

int main() {
    int xa, ya, xb, yb, ans = 0, n;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    while (n--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        long long  A = linear(a, b, c, xa, ya);
        long long B = linear(a, b, c, xb, yb);
        ans += ((A > 0 && B < 0) || (A < 0 && B > 0));

    }

    printf("%d", ans);

    return 0;
}