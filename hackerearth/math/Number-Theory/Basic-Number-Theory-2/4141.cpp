#include <bits/stdc++.h>

using namespace std;

int a[50005];

int main() {
    int t, c, n;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d %d", &a[0], &a[1], &c, &n);
        
        int cur = a[0] * 10 + (n >= 2 ? a[1] : 0);
        for (int i = 2; i <= n - 1; ++i) {
            a[i] = (a[i - 1] * c + a[i - 2]) % 10;
            cur = cur * 10 + a[i];
            cur %= 41;
        }

     printf("%s\n", cur % 41 == 0 ? "YES" : "NO");
    }

    return 0;
}