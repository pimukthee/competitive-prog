(n ^ k) % mod

long long p(long long n, long long k) {
    long long d = 1;
    while(k){
        if(k & 1)
            d = (d * n) % mod;
        n = (n * n) % mod;
      k >>= 1;
    }
    
    return d;
}
