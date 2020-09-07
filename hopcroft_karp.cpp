void colorGraph(int x, bool c) {
	if (!c) color[x] = 1;
	else color[x] = 2;
	vis[x] = 1;
	trav(i,adj[x]) {
		if (!vis[i]) {
			colorGraph(i,!c);
		}
	}
}
bool bfs(int m) {
    queue<int> q;
    forr(u,0,m+1) {
        if (!pairU[u]) {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INT_MAX;
    }
    dist[0] = INT_MAX;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[0]) {
            trav(i,adj[u]) {
                if (dist[pairV[i]] == INT_MAX) {
                    dist[pairV[i]] = dist[u]+1;
                    q.push(pairV[i]);
                }
            }
        }
    }
    return dist[0] != INT_MAX;
}
bool dfs(int u) {
    if (u) {
        trav(i,adj[u]) {
            if (dist[pairV[i]] == dist[u]+1) {
                if (dfs(pairV[i])) {
                    pairV[i] = u;
                    pairU[u] = i;
                    return 1;
                }
            }
        }
        dist[u] = INT_MAX;
        return 0;
    }
    return 1;
}
int hopcroftKarp(int n, int m) {
    pairU = new int[m+1];
    pairV = new int[n+1];
    dist = new int[m+1];
    forr(u,0,m+1) pairU[u] = 0;
    forr(v,0,n+1) pairV[v] = 0;
    int result = 0;
    while (bfs(m)) {
        forr(u,1,m+1) {
            if (!pairU[u] && dfs(u)) result++;
        }
        return result;
    }
    return -1;
}
void solve() {
    int nodes; // # nodes in graph
    forr(i,0,nodes) if (!vis[i]) colorGraph(i,0);
    int a = 0, b = 0;
    trav(i,color) {
        if (i == 1) a++;
        if (i == 2) b++;
    }
    cout << "hopcroftKarp(max(a,b),min(a,b));
}
