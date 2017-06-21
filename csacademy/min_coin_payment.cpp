#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, sum = 0;
    cin >> k;
    sum += k/50;
    k %= 50;
    sum += k/5;
    k %= 5;
    cout << sum + k;
    return 0;
}