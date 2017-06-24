#include <bits/stdc++.h>

using namespace std;

int a[2005], dp[2005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    dp[i] =  1;
    for (int j = i - 1; j >= 0; --j) {
      if (a[i] % a[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  printf("%d", *max_element(dp, dp + n));

  return 0;
}
