vi adj[mxN];
bool vis[mxN];

void dfs(int x) {
	trav(i,adj[x]) if (!vis[i]) {
		vis[i] = 1;
		dfs(i);
	}
	topo.pb(x);
}
void solve() {
	forr(i,0,n) if (!vis[i]) {
		vis[i] = 1;
		dfs(i);
	}
	reverse(all(topo));
	trav(i,topo) cout << i << " ";
}
