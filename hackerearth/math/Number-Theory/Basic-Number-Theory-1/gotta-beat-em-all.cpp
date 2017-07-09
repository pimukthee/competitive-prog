#include <bits/stdc++.h>

#define MAXN 1000005

using namespace std;

bool p[MAXN];
vector <int> prime;
int factor_count[MAXN];
int cnt[MAXN], sum[MAXN];

void count_factor(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) factor_count[j]++;
    sum[factor_count[i]]++;
  }
}

void qsum(int n) {
  for (int i = 2; i <= n; ++i) sum[i] += sum[i - 1];
}

int main() {
  int t, n;
  scanf("%d %d", &t, &n);

  count_factor(n);
  qsum(n);

  while (t--) {
    int k;
    scanf("%d", &k);
    printf("%d\n", sum[factor_count[k] - 1]);
  }

  return 0;
}
