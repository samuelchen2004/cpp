int sz[mxN], par[mxN];

int get(int x) {return x == par[x] ? x : par[x] = get(par[x]);}
void unite(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x,y);
	par[x] = y;
	sz[y] += sz[x];
}
void solve() {
	forr(i,0,n+5) {
		sz[i] = 1;
		par[i] = i;
	}
}
