#include <bits/stdc++.h>

using namespace std;

string score[105];
int success[105];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) cin >> score[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char max_score = '0';
            for (int k = 0; k < n; ++k) max_score = max(max_score, score[k][j]);
            if (score[i][j] == max_score) success[i] = 1;
        }
    }

    cout << accumulate(success, success + n, 0) << endl;

    return 0;
}