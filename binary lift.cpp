// mainly for forests, lca template already has binary lift

int up[mxN][25]; // reminder: set up[0][0] = -1 if needed

void init_lift() {
	forr(i,1,25) forr(j,0,n) {
		if (up[j][i-1] >= 0) up[j][i] = up[up[j][i-1]][i-1];
		else up[j][i] = -1;
	}
}
int lift(int x, int k) {
	forr(i,0,25) if ((k >> i) & 1) {
		x = up[x][i];
		if (x == -1) return x;
	}
	return x;
}
