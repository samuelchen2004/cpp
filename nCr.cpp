ll fac[mxN];
ll invFac[mxN];

void initFac() {
	fac[0] = 1, invFac[0] = 1;
    for (int i = 1; i < mxN; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
        invFac[i] = modInv(fac[i]);
    }
}
ll C(ll n,ll r) {ll res = (((fac[n]*invFac[n-r])%MOD)*invFac[r])%MOD; return res;}
