#include <bits/stdc++.h>

using namespace std;

double pos(int cnt, int k) {
    if (k == 0) {
        return (cnt == 0 ? 1.0 : 0.0);
    } else {
        return pos(cnt + 1, k - 1) + pos(cnt - 1, k - 1);
    }
}

int main () {
    string str, str1;
    int cnt = 0, k = 0;

    cin >> str >> str1;

    for (auto c : str) {
        if (c == '+') ++cnt;
        else --cnt;
    }
    for (auto c : str1) {
        if (c == '+') --cnt;
        else if (c == '-') ++cnt;
        else ++k;
    }

    printf("%.9lf", pos(cnt, k) / (1 << k));
    
    return 0;
}