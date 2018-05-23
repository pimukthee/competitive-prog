#include <bits/stdc++.h>

using namespace std;

int head[30000+10];

int findhead(int x) {
    if (head[x] == x) {
        return x;
    } else {
        return head[x] = findhead(head[x]);
    }
}

bool is_same_set(int v) {
    return findhead(0) == findhead(v);
}

int main() {
    int n, m, u, v, k;
    while (scanf("%d %d", &n, &m) && n+m) {

        for (int i = 0; i <= n; ++i) head[i] = i;

        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &k, &u);
            u = findhead(u);
            for (int i = 1; i < k; ++i) {
                scanf("%d", &v);
                v = findhead(v);
                head[v] = u;
            }
        }

        u = findhead(0);
        int ans = count_if(head, head + n, is_same_set);

        printf("%d\n", ans);
    }
    return 0;
}
