#include <bits/stdc++.h>

using namespace std;

bool p[1000005];
vector <int> v;


int main() {
    for (int i = 2; i <= 1000000; ++i) {
        if (!p[i]) {
            v.push_back(i);
            for (int j = i + i; j <= 1000000; j += i)
                p[j] = true;
        }
    }

    cout << v.size() << endl;

    return 0;
}