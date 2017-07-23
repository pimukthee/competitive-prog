#include <bits/stdc++.h>

#define LL long long

using namespace std;

bool isPrime(LL n) {
    for(LL i = 2; i*i <= n; ++i) {
        if(n%i==0) {
            return false;
        }
    }

    return true;
}
int main() {
    LL n;
    cin >> n;

    if(isPrime(n)) cout << 1;
    else if(n & 1) {
        if(isPrime(n - 2)) cout << 2;
        else cout << 3;
    }
    else cout << 2;

    return 0;
}
