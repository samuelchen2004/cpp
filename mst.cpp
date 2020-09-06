struct Edge {int u, v, weight;};
bool sortedge(const Edge& e1, const Edge& e2) {return e1.weight < e2.weight;}
// change to e1.weight > e2.weight for maximum spanning tree
void solve() {
	vector<Edge> edges;
	// push edges into {vector<Edge> edges} here
	int cost = 0;
	vi tree_id(n);
	vector<Edge> result;
	forr(i,0,n) tree_id[i] = i;
	sort(edges.begin(),edges.end(),sortedge);
	trav(e,edges) {
	    if (tree_id[e.u] != tree_id[e.v]) {
	        cost += e.weight;
	        result.pb(e);
	        int old_id = tree_id[e.u], new_id = tree_id[e.v];
	        forr(i,0,n) {
	            if (tree_id[i] == old_id) {
	                tree_id[i] = new_id;
	            }
	        }
	    }
	}
}
