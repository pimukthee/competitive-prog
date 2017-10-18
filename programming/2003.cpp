#include <bits/stdc++.h>

using namespace std;

int n, dp[4][4][4][4], next_state[4][4][4][4];
char coals[100005];

int cost(int f, int s, int coal) {
    int res = (f!=s) + (f!=coal) + (s!=coal);
    return res + !res - !f;
}

int main() {
    char c;
    int ans = -1;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &c);
        coals[i] = (c == 'M' ? 1 : ( c == 'B' ? 2 : 3));
    }
    memset(next_state, -1, sizeof next_state);
    next_state[0][0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        memcpy(dp, next_state, sizeof next_state);
        memset(next_state, -1, sizeof next_state);
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        if (dp[j][k][l][m] != -1) {
                            int first_mine = dp[j][k][l][m] + cost(k, j, coals[i]);
                            int second_mine = dp[j][k][l][m] + cost(m, l, coals[i]);
                            next_state[coals[i]][j][l][m] = max(next_state[coals[i]][j][l][m], first_mine);
                            next_state[j][k][coals[i]][l] = max(next_state[j][k][coals[i]][l], second_mine);
                            ans = max(ans, max(first_mine, second_mine));
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
