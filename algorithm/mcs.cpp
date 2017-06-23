#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> num(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> num[i];

  // dp best between ch
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    sum = max(num[i], sum + num[i]);
    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
