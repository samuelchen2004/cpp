vi sieve(int N) {
	bool prime[N+1]; fill(prime,prime+N+1,1);
	for (int p = 2; p*p <= N; p++) if (prime[p]) {
		for (int i = p*p; i <= N; i += p) prime[i] = 0;
	}
	vi v; forr(p,2,N+1) if (prime[p]) v.pb(p);
	return v;
}
