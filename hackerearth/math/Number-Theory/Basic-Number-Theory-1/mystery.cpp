#include <bits/stdc++.h>

using namespace std;

int find_number_of_factor(int n) {
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
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", find_number_of_factor(n));
    }
    return 0;
}