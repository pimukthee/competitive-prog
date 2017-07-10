#include <bits/stdc++.h>

using namespace std;

int no_of_divisors(int n) {
    map <int, int> factors;
    for (int i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt) factors[i] = cnt;
    }
    
    if (n != 1) factors[n] = 1;

    int ans = 1;
    for (auto& factor : factors) ans *= (factor.second + 1);

    return ans;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string str;
        cin >> str;
        
        int value = 0;
        for_each(str.begin(), str.end(), [&value](char c) {
           value += tolower(c) - 'a' + 1;
        });
        
        cout << (no_of_divisors(value) >= (int)str.size() ? "IN\n" : "OUT\n");
    }
    
    return 0;
}