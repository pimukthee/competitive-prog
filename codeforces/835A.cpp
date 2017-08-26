#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int f = s*v1 + 2*t1, se = s*v2 + 2*t2;
    if (f < se) {
        cout << "First\n";
    } else if (f > se) {
        cout << "Second\n";
    } else {
        cout << "Friendship\n";
    }

    return 0;
}