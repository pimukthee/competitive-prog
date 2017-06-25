#include <bits/stdc++.h>

using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    else return n * fact(n - 1);
}

char alp[500];

int main() {
    string str;
    cin >> str;

    for (auto &c : str) alp[c]++;
    long long dup = 1;
    for (char c = 'a'; c <='z'; ++c) dup *= fact(alp[c]);

    cout << fact((long long)str.size()) / dup << endl;
   
    return 0;
}