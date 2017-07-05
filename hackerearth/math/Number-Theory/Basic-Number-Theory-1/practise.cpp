#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll mod, x ,y, gcd;

ll p(ll n, ll k) {
    ll d = 1;
    while(k){
        if(k & 1)
            d = (d * n) % mod;
        n = (n * n) % mod;
      k >>= 1;
    }
    
    return d;
}

void extended_euclid(ll a, ll b) {
    if (b == 0) {
        gcd = a;
        x = 1;
        y = 0;
    } else {
        extended_euclid(b, a % b);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}

ll mod_inverse(ll a, ll m) {
    extended_euclid(a, m);
    return (x % m + m) % m;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c >> mod;

    ll ans1 = p(a, b);
    ll ans2 = mod_inverse(c, mod);

    cout << ((ans1 % mod) * (ans2 % mod)) % mod;
    return 0;
}