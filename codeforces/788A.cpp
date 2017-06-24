#include <bits/stdc++.h>

using namespace std;
vector <int> f;
int state[2] = {1, -1};

long long mcs(int l, int n, int idx) {
    long long s = 0, p = -1000000000;
    for(int i = l; i < n; i++) {
        long long val = f[i] * state[idx];
        s = max(s + val, val);
        p = max(s, p);
        idx ^= 1;
    }
    return p;
}

int main() {
    int n, a, b;

    scanf("%d %d", &n, &a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        f.push_back(abs(a - b));
        a = b;
    }
    //printf("%d ", mcs(1, f.size(), 1));
    printf("%I64d", max(mcs(0, f.size(), 0), mcs(1, f.size(),0)));

    return 0;
}
