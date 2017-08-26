#include <bits/stdc++.h>

using namespace std;

int dig[10];

int main() {
    int k, sum = 0;
    string n;
    cin >> k >> n;
    for (char c : n) {
        sum += c - '0';
        ++dig[c-'0'];
    }
    int dif = k-sum, ans = 0;
    if (dif > 0) {
        for (int i = 0; i <= 9; ++i) {
            while (dig[i] && dif > 0) {
                ++ans;
                --dig[i];
                dif -= 9-i;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}