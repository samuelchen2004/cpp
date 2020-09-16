vector<int> adj[mxN];
int match[mxN];
int dist[mxN];

// current node maximum at 1e5, change accordingly
bool bfs() {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < 1e5; i++) {
		if (match[i] == -1) {
			q.push(i);
			dist[i] = 0;
		}
	}
	bool reached = false;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int v : adj[x]) {
			if (match[v] == -1) reached = true;
			else if (dist[match[v]] == -1) {
				dist[match[v]] = dist[x] + 1;
				q.push(match[v]);
			}
		}
	}
	return reached;
}
bool dfs(int x) {
	if (x == -1) return true;
	for (int v : adj[x]) {
		if (match[v] == -1 || dist[match[v]] == dist[x] + 1) {
			if (dfs(match[v])) {
				match[v] = x, match[x] = v;
				return true;
			}
		}
	}
	return false;
}
int hopcroft_karp() {
	memset(match, -1, sizeof match);

	int matching = 0;
	while (bfs()) {
		for (int i = 0; i < 1e5; i++)
			if (match[i] == -1 && dfs(i))
				matching++;
	}
	return matching;
}
