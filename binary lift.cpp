int up[mxN][25]; // tree is rooted at 1, not 0

void init_lift() {
	forr(i,1,25) forr(j,1,n+1) up[j][i] = up[up[j][i-1]][i-1];
}
int lift(int x, int k) {
	forr(i,0,25) if ((k >> i) & 1) x = up[x][i];
	return x ?: -1;
}
