#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  stack <int> st;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    if (st.empty() || ((st.top() & 1) != (k & 1))) st.push(k);
  }
  printf("%d", n - st.size());
  return 0;
}
