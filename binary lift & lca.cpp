int n, l;
vi adj[mxN];
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    forr(i,1,l+1) up[v][i] = up[up[v][i-1]][i-1];
    trav(u,adj[v]) if (u != p) dfs(u,v);
    tout[v] = ++timer;
}
int binary_lift(int x, int k) {
	int idx = 0, num = 1;
	while (k > 0) {
		while (k-2*num >= 0) {idx++; num *= 2;}
		k -= num;
		return binary_lift(up[x][idx],k);
	}
	return up[x][idx];
}
bool is_ancestor(int u, int v) {return tin[u] <= tin[v] && tout[u] >= tout[v];}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    ford(i,l+1,0) if (!is_ancestor(up[u][i],v)) u = up[u][i];
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
