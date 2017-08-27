#include <bits/stdc++.h>

#define make_pair mp

using namespace std;

int arr[1005][1005], painting[1005][1005];
int t, w, h;

void paint(int r, int c, int s) {
    for (int i = r; i < r + s; ++i)
        for (int j = c; j < c + s; ++j)
            painting[i][j] ^= 1;
}

void rec(int i, int j) {
    if (i <= h && j <= w) {
        if (eq()) {
             ans = true;
             return;
        }
        if (arr[i][j] != painting[i][j]) {
            for (int s = 1; ; ++s) {
                if (s+j-1 > w || s+i-1 > w) break;
                paint(i, j, s);
                if (j+1 > h) rec(i+1, 1);
                else rec(i, j+1);
                if (ans) {
                    mem.push_back(mp(mp(i, j), s));
                    return;
                }
                paint(i, j, s);
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &w, &h);
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        rec(1, 1);
    }
    return 0;
}