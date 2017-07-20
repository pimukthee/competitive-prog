#include <iostream>

using namespace std;

int main() {
  int t;
  unsigned long long x, n, ans;
  
  cin >> t;
  
  while (t--) {
    cin >> x >> n;
    ans = 0;
    while (x >= n) {
      ans += x/n * n;
      x = x/n + x%n;
    }
    cout << ans << endl;
  }
  
  return 0;
}