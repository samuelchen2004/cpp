int n, vis[mxN]; // vis[] is int to store {0,1,2}
vi adj[mxN], topo;
bool cycle;

void dfs(int x) {
	vis[x] = 1;
	trav(i,adj[x]) {
		if (vis[i] == 1) {cycle = 1; return;}
		if (!vis[i]) dfs(i);
	}
	vis[x] = 2;
	topo.pb(x);
}
void solve() {
	forr(i,0,n) if (!vis[i]) dfs(i);
	reverse(all(topo));
	trav(i,topo) cout << i << " ";
}
