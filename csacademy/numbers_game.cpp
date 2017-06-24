#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, ans = 0;
    scanf("%d %d", &n, &a);
    while (--n) {
        scanf("%d", &b);
        if (b / 10 != a % 10) ans++;
        a = b;
    }

    printf("%d\n", ans);
    return 0;
}