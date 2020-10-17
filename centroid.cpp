int q = -1, n, a, b, sz[mxN], depth[mxN];
vi adj[mxN];

int init_size_and_depth(int v, int p = -1) {
	if (p != -1) depth[v] = depth[p]+1;
	sz[v] = 1;
	trav(x,adj[v]) {
		if (x != p) {
			sz[v] += init_size_and_depth(x,v);
		}
	}
	return sz[v];
}
int find_centroid(int v, int p, int n) {
	trav(x,adj[v]) {
		if (x != p && sz[x] > n/2) {
			return find_centroid(x,v,n);
		}
	}
	return v;
}

void solve() {
  cin >> n;
  forr(i,0,n-1) {
    cin >> a >> b; a--; b--;
    adj[a].pb(b); adj[b].pb(a);
  }
  init_size_and_depth(0);
  int c = fin_centroid(0,-1,sz[0]);
}
