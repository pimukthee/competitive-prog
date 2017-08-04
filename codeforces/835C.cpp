#include <bits/stdc++.h>

using namespace std;

vector <int> p[105][105];
int dp[15][105][105];

int main() {
    int n, q, c, x, y, s, t, x2, y2;
    scanf("%d %d %d", &n, &q, &c);
    while (n--) {
        scanf("%d %d %d", &x, &y, &s);
        p[x][y].push_back(s);
    }

    for (int i = 0; i <= c; ++i) {
        for (int j = 1; j <= 100; ++j) {
            for (int k = 1; k <= 100; ++k) {
                for (int b : p[j][k]) dp[i][j][k] += (b+i) % (c+1);
                dp[i][j][k] += dp[i][j-1][k] + dp[i][j][k-1] - dp[i][j-1][k-1];
            }
        }
    }

    while (q--) {
        scanf("%d %d %d %d %d", &t, &x, &y, &x2, &y2);
        t %= (c+1);
        printf("%d\n", dp[t][x2][y2] - dp[t][x-1][y2] - dp[t][x2][y-1] + dp[t][x-1][y-1]);
    }

    return 0;
}