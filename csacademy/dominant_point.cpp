#include <bits/stdc++.h>

using namespace std;

pair <int, pair<int, int> > a[1005];

bool cmp(const pair <int, pair<int, int> > &x
         , const pair <int, pair<int, int> > &y) {
  if (x.second.first != y.second.first) return x.second.first > y.second.first;
  return x.second.second > y.second.second;
}

int main() {
  int n;
  bool ans = true;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].second.first, &a[i].second.second);
    a[i].first = i + 1;
  }
  sort(a, a + n, cmp);
  for (int i = 1; i < n; ++i) {
    if (a[i].second.second >= a[0].second.second) {
      ans = false;
    }
  }
  printf("%d", ans ? a[0].first : -1);
  return 0;
}
