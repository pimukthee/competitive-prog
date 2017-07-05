#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, p;
    
    cin >> n >> x;
    
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        if (x - p <= 0 && x > 0) cout << i;
        x -= p;
    }
    
    return 0;
}
