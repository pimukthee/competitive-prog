#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cur = 0, ans = -1, h;

    scanf("%d", &n);
    
    while (n--) {
        scanf("%d", &h);
        ans += abs(cur - h) + 2;
        cur = h;
    }

    printf("%d", ans);

    return 0;
}