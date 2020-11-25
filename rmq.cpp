int st[mxN][25], lg[mxN];

void build() {
	forr(i,0,n) st[i][0] = arr[i];
	forr(j,1,26) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = min(st[i][j-1],st[i + (1 << (j-1))][j-1]);
		}
	}
	forr(i,2,mxN) lg[i] = lg[i/2]+1;
}
int rmq(int l, int r) {
	int j = lg[r-l+1];
	return min(st[l][j],st[r - (1 << j) + 1][j]);
}
