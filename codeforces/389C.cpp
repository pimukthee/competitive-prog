#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> pile;
    vector <int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    sort(x.begin(), x.end());
    for (auto strength : x) {
        bool is_put = false;
        for (auto& no_of_box : pile) {
            if (strength >= no_of_box) {
                ++no_of_box;
                is_put = true;
                break;
            }
        }
        if (!is_put) pile.push_back(1);
    }

    cout << pile.size();

    return 0;
}