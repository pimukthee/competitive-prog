#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, c[20];

int count_possible_way(int i, int total, int hardest, int easiest, int chosen) {
    if (i == n) return ((total >= l && total <= r) && (hardest - easiest >= x) && chosen >= 2);
    else {
        return count_possible_way(i + 1, total + c[i], max(hardest, c[i]), min(easiest, c[i]), chosen + 1) 
               + count_possible_way(i + 1, total, hardest, easiest, chosen);
    }
}

int main() {

    cin >> n >> l >> r >> x;
    
    for (int i = 0; i < n; ++i) cin >> c[i];

    cout << count_possible_way(0, 0, 0, 1e6 + 10, 0) << endl;

    return 0;
}