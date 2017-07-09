#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000100

#define LL long long

using namespace std;

LL fac[MAXN + 10], inv[MAXN + 10];
int arr[100];

bool is_vowel(char c) {
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

LL mpow(LL a, LL n) {
    LL ret = 1;
    while (n) {
        if (n & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

void precalc() {
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = mpow(fac[i], MOD - 2);
    }
}

LL choose(LL n, LL r) {
    if (n <= 0 || r < 0 || n < r) return 0;
    return ((fac[n] * (inv[r])) % MOD * (inv[n - r])) % MOD;
}

int main() {
    precalc();

    int t;

    cin >> t;
   
    while (t--) {
        string str;
        cin >> str;

        for (int i = 0; i < 26; ++i) arr[i] = 0;
        for (auto c : str) arr[c - 'a']++;
        int vowel = arr[0] + arr[4] + arr[8] + arr[14] + arr[20];
        int consonant = str.size() - vowel;
        int possible = consonant + 1;
        LL p = choose(possible, vowel);
        if (possible < vowel) {
            cout << -1 << endl;
        } else {
            LL q = fac[vowel];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (is_vowel(c))
                    q = (q * inv[arr[c - 'a']]) % MOD;  
            } 
            q = (q * fac[consonant]) % MOD;
            for (char c = 'a'; c <= 'z'; ++c){
                if (!is_vowel(c))
                    q = (q * inv[arr[c - 'a']]) % MOD;
            }
            p = (p * q) % MOD;

            cout << p << endl;
        }
    }

    return 0;
}
