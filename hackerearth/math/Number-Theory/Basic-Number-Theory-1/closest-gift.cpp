#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return n <= 1 ? false : true;
}

int main() {
    int n;
    cin >> n;

    for (int i = n; ; ++i) {
        if (is_prime(i)) {
            printf("%d", i - n);
            break;
        }
    }

    return 0;
}