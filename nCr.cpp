ll fac[mxN], invFac[mxN];

void initFac() {
	fac[0] = 1, invFac[0] = 1;
	forr(i,1,mxN) {
		fac[i] = (i*fac[i-1]) % MOD;
		invFac[i] = modInv(fac[i]);
    }
}
ll C(ll n,ll r) {ll res = (((fac[n]*invFac[n-r])%MOD)*invFac[r])%MOD; return res;}
