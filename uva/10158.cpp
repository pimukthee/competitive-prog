#include <bits/stdc++.h>

using namespace std;

int head[20000+10],n;

int findhead(int x) {
    if (head[x] == x) {
        return x;
    } else {
        return head[x] = findhead(head[x]);
    }
}

bool is_friend(int u, int v) {
    return findhead(u) == findhead(v);
}

bool is_enemy(int u, int v) {
    return findhead(u+n) == findhead(v) || findhead(u) == findhead(v+n);
}

int main() {
    int c, u ,v;

    scanf("%d", &n);
    for (int i = 0; i <= 2*n; ++i) head[i] = i;

    while (scanf("%d %d %d", &c, &u, &v) && c+u+v) {

        if (c == 1) {
            if (is_enemy(u, v)) {
                printf("-1\n");
            } else {
                head[findhead(v)] = findhead(u);
                head[findhead(n+v)] = findhead(n+u);
            }
        } else if (c == 2) {
            if (is_friend(u, v)) {
                printf("-1\n");
            } else {
                head[findhead(n+v)] = findhead(u);
                head[findhead(n+u)] = findhead(v);
            }
        } else if (c == 3) {
            printf("%d\n", is_friend(u, v));
        } else {
            printf("%d\n", is_enemy(u, v));
        }

    }
    return 0;
}
