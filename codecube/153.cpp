#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

int main() {
  int n, h;
  cin >> n >> h;

  dp[1][1] = dp[0][0] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= h; ++j) {
      for (int k = 0; k < i; ++k) {
        for (int l = 0; l < min(j, k + 1); ++l) {
          printf("i = %d j = %d k  = %d l = %d rk = %d rl = %d left = %d right = %d\n", i, j,k , l, i - k - 1, j - 1, dp[k][l], dp[i - k - 1][j - 1]);
          dp[i][j] += dp[k][l] * dp[i - k - 1][j - 1];
        }
      }
    }
  }

  cout << dp[n][h];

  return 0;
}

