int depth[mxN], up[mxN][25];
vi adj[mxN];

void init_lift(int x = 0, int p = -1) {
	forr(i,0,25) {
		if (!i) up[x][i] = max(p,0);
		else up[x][i] = up[up[x][i-1]][i-1];
	}
	if (p != -1) depth[x] = depth[p]+1;
	trav(u,adj[x]) if (u != p) init_lift(u,x);
}
int lift(int x, int k) {
	forr(i,0,25) if ((k >> i) & 1) x = up[x][i];
	return x;
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	a = lift(a, depth[a]-depth[b]);
	if (a == b) return a;
	ford(i,25,0) {
		int nxa = up[a][i], nxb = up[b][i];
		if (nxa != nxb) a = nxa, b = nxb;
	}
	return up[a][0];
}
int dist(int a, int b) {
	return depth[a] + depth[b] - 2*depth[lca(a,b)];
}
bool anc(int a, int b) {
	return lift(b, depth[b]-depth[a]) == a;
}
bool in(int a, int b, int c) {
	// returns true if c is on the path from a to b
	int l_ab = lca(a,b);
	int l_ac = lca(a,c);
	int l_bc = lca(b,c);
	if (l_ab == c) return 1;
	if (l_ac == l_ab && l_bc == c) return 1;
	if (l_bc == l_ab && l_ac == c) return 1;
	return 0;
}
int get_node_on_path(int a, int b, int c) {
	// returns closest node from c thats on path from a to b
	int l_ab = lca(a,b);
	int l_ac = lca(a,c);
	int l_bc = lca(b,c);
	if (depth[l_ac] > depth[l_ab]) return l_ac;
	if (depth[l_bc] > depth[l_ab]) return l_bc;
	return l_ab;
}
