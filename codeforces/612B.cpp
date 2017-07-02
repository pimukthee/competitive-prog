#include <bits/stdc++.h>

using namespace std;

int sec[200005];

int main() {
  int n, f;
  long long ans = 0;

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &f);
    sec[f] = i;
  }

  for (int i = 2; i <= n; ++i) ans += 1ll * abs(sec[i] - sec[i - 1]);

  cout << ans;

  return 0;
}
