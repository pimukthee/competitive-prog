#include <bits/stdc++.h>

using namespace std;

char cell[200][200];

bool is_cross(int i, int j) {
    return (cell[i][j] == '#' && 
            cell[i + 1][j] == '#' && 
            cell[i + 1][j - 1] == '#' && 
            cell[i + 1][j + 1] == '#' && 
            cell[i + 2][j] == '#');
}

int main() {
    int n;
    bool ans = true;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf(" %s", cell[i] + 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cell[i][j] == '#') {
                if (is_cross(i, j)) {
                    cell[i][j] = cell[i + 1][j] = cell[i + 1][j - 1] = cell[i + 1][j + 1] = cell[i + 2][j] = '.';
                } else {
                    ans = false;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) ans = ans && all_of(cell[i] + 1, cell[i] + n + 1, [](char c) { return c == '.';});

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}