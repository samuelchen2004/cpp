vi sieve(int n) {
    bool prime[n+1];
    fill(prime,prime+n+1,1);
    for (int p = 2; p*p <= n; p++) {
    	if (prime[p]) {
    		for (int i = p*p; i <= n; i += p) {
    			prime[i] = 0;
    		}
    	}
    }
    vi v;
    forr(p,2,n+1) if (prime[p]) v.pb(p);
    return v;
}
