#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double k, product = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lf", &k);
        product *= pow(k, 1.0/n);
    }

    printf("%.18lf\n", product);

    return 0;
}