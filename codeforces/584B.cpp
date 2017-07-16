#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

long long pow(long long n,long long k) {
    long long ans = 1;
    while(k) {
        if(k & 1) ans=(ans * n) % mod;
        n=(n * n) % mod;
        k >>= 1;
    }
    return ans;
}

int main() {
    long long n;
    
    cin >> n;
    
    cout << (pow(3ll,3*n)-pow(7ll,n)+mod)%mod;

    return 0;
}
