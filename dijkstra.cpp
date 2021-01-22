const int mxN = 2e5+5;
int n, m, dist[mxN];
vpi adj[mxN];
bool vis[mxN];

void solve() {
	cin >> n >> m;
	forr(i,0,m) {
		int a, b, w; cin >> a >> b >> w; a--, b--;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}
	fill(dist,dist+n,1e9);
	dist[0] = 0;
	priority_queue<pi> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		int a = pq.top().s;
		pq.pop();
		if (vis[a]) continue;
		vis[a] = 1;
		trav(i,adj[a]) {
			int b = i.f, w = i.s;
			if (ckmin(dist[b], dist[a]+w)) {
				pq.push({-dist[b],b});
			}
		}
	}
	forr(i,0,n) cout << dist[i] << " \n"[i==n-1];
}
