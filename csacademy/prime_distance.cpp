#include <bits/stdc++.h>

using namespace std;

int count_factor(int &a, int factor) {
  int number_of_factor = 0;
  while(a % factor == 0) {
    a /= factor;
    number_of_factor++;
  }

  return number_of_factor;
}

int main() {
  int a, b, ans = 0;
  cin >> a >> b;
  for (int i = 2; i * i <= a || i * i <= b; ++i) {
    ans += abs(count_factor(a, i) - count_factor(b, i));
  }
  cout << ans + (a !=b ? (a != 1) + (b != 1) : 0);

  return 0;
}
