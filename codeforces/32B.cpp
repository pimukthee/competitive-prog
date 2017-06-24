#include <bits/stdc++.h>
using namespace std;

int bitcount(int x) {
    if(x <= 1)
        return 0;
    else
        return 1 + bitcount(x - (x & -x));
}
int main() {
    int x;
    cin >> x;
    cout << bitcount(x) << "\n";
    return 0;
}
