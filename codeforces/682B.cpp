#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    for (int i = 1, j = 0; i <= n + 1; ++i, ++j) {
        while (i > a[j] && j <= n) ++j;
        if (j == n + 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}