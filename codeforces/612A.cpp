#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p, q, nq = -1, np = -1;
  string str;

  cin >> n >> p >> q;
  cin >> str;

  for (int i = 0; i <= n / p; ++i) {
    int len = i * p, rest = str.size() - len;
    if (rest % q == 0) {
      np = i;
      nq = rest / q;
    }
  }

  if (nq + np != -2) {
    int stop = np > 0 ? p - 1 : q - 1;
    //cout << stop << endl;
    cout << np + nq << endl;
    for (int i = 0; str[i]; ++i) {
        if (i == stop) {
          cout << str[i] << endl;
          //cout << i << " " << np * p << endl;
          if (i >= np * p - 1) stop += q;
          else stop += p;
        } else {
          cout << str[i];
        }
    }
  } else {
    cout << -1;
  }

  return 0;
}
