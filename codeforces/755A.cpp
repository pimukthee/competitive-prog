#include <bits/stdc++.h>

using namespace std;

bool p[2000005];

int main () {
    for (int i = 2; i <= 2000000; ++i) {
        if (!p[i]) {
            for (int j = i + i; j <= 2000000; j += i) 
                p[j] = true;
        }
    }
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= 1000; ++i) {
        if (p[n * i + 1]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}