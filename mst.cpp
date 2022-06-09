int sz[mxN], par[mxN];

int get(int x) {return x == par[x] ? x : par[x] = get(par[x]);}
void unite(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x,y);
	par[x] = y;
	sz[y] += sz[x];
}
struct Edge {
	ll u, v, weight;
	bool operator<(Edge const& other) const {
		return weight < other.weight;
	}
};
void solve() {
	forr(i,0,n+5) {
		sz[i] = 1;
		par[i] = i;
	}
	vector<Edge> edges, result;
	ll cost = 0;
	forr(i,0,m) {
		int a, b; cin >> a >> b; a--, b--;
		edges.pb({a,b});
	}
	sort(all(edges));
	trav(e,edges) {
		if (get(e.u) != get(e.v)) {
			cost += e.weight;
			result.pb(e);
			unite(e.u, e.v);
		}
	}
}
