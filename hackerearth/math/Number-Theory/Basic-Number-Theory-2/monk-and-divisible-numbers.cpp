#include <bits/stdc++.h>

#define ll long long
#define mll map <long long, long long>

using namespace std;

const ll MOD = 1e9 + 7;

mll faca, facb;

mll find_factor(ll n, ll c) {
    map <ll, ll> fac;

    for (ll i = 2; i * i <= n; ++i) {
        ll cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) fac[i] = cnt * c;
    }
    if (n != 1) fac[n] = c;

    return fac;
}

ll p(ll n, ll k) {
    ll d = 1;

    while (k) {
        if (k & 1) d = (d * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }

    return d;
}

int main() {
    int t;
    ll a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        facb = find_factor(b, c);
        faca = find_factor(a, 1);
        ll ans = 1;
        for (auto i : facb) {
            //cout << i.first << ' ' << i.second << endl;
            ans = (ans * p(i.first % MOD, max(0ll, (i.second - faca[i.first])))) % MOD;
        }

        cout << ans << endl;
    }
    return 0;
}