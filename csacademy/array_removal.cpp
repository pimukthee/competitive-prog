#include <bits/stdc++.h>

using namespace std;

bool vis[100005];
vector<long long> ans;
int head[100005];
long long sum[100005];

int findhead(int x) {
  if (x == head[x])
    return x;
  else
    return head[x] = findhead(head[x]);
}

void merge(int a, int b) {
  int u = findhead(a);
  int v = findhead(b);
  sum[v] += sum[u];
  head[u] = v;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1);
  vector<int> b(n);
  for (int i = 0; i <= n; ++i) head[i] = i;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  reverse(b.begin(), b.end());
  for (auto i : b) {
    vis[i] = true;
    sum[i] += a[i];
    if (ans.empty()) ans.push_back(sum[i]);
    else {
      if (vis[i - 1]) merge(i - 1, i);
      if (vis[i + 1]) merge(i, i + 1);
      ans.push_back(max(ans.back(), sum[findhead(i)]));
    }
  }
  reverse(ans.begin(), ans.end());

  for (auto i : ans) printf("%lld\n", i);
  return 0;
}