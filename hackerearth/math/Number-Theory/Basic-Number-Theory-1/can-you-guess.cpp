#include <bits/stdc++.h>

using namespace std;

int find_sum(int n) {
    int sum = (n > 1);

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }

    return sum;
}

int main() {
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        cout << find_sum(n) << endl;
    }
    return 0;
}