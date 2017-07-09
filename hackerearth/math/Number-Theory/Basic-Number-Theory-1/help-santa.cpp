#include <bits/stdc++.h>

using namespace std;

float dist(pair <float, float> a, pair <float, float> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  set <float> dis;
  pair <float, float> p[5];

  for (int i = 0; i < 4; ++i) scanf("%f %f", &p[i].first, &p[i].second);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; j++) {
      if (i != j) {
        dis.insert(dist(p[i], p[j]));
      }
    }
  }

  cout << (dis.size() == 2 ? "true" : "false");

  return 0;
}
