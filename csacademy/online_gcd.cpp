#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main() {
  int n, m;
  scanf("%d %d %d", &n, &m, &a[1]);
  int gcd = a[1];
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &a[i]);
    gcd = __gcd(gcd, a[i]);
  }
  while (m--) {
    int idx, val;
    scanf("%d %d", &idx, &val);
    a[idx] /= val;
    gcd = __gcd(gcd, a[idx]);
    printf("%d\n", gcd);
  }

  return 0;
}
