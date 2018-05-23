#include <bits/stdc++.h>

using namespace std;

int arr[100];

int main() {
    int n, c = 0;
    while (scanf("%d", &n) && n) {

        int sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        sum /= n;
        for (int i = 0; i < n; ++i) ans += arr[i] > sum ? arr[i] - sum: 0;

        ++c;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", c, ans);
    }
    return 0;
}
