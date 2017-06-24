#include <bits/stdc++.h>

using namespace std;

int arr[105][105];

int main() {
    int n, idx, ans = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) scanf("%d", &arr[i][j]);

    for (int i = 1; i <= n; ++i) {
        int score = 0;
        for (int j = 1; j <= n; j++) {
            score += (arr[i][j] == 1);
            score += (arr[j][i] == 2);
        }
        if (score > ans) {
            ans = score;
            idx = i;
        }
    }

    printf("%d", idx);
    return 0;
}