#include <bits/stdc++.h>

#define pll pair<long long, long long>

using namespace std;

vector <pll > c;

bool cmp(const pll &l,const pll &r) {

    return l.first < r.first;
}

int main() {
    int n;
    long long a, b;
    
    scanf("%d", &n);

    for (long long i = 1; i <= 1000000; ++i) c.push_back(make_pair(i*i*i, i));

    while (n--) {
        scanf("%lld %lld", &a, &b);
        auto k = *lower_bound(c.begin(), c.end(), make_pair(a*b, 0), cmp);
        if (k.first != a * b) {
            printf("No\n");
        } else {
            if (a % k.second == 0 && b % k.second == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}