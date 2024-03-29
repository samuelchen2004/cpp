/* if n is not the max index of the segtree (specifically, if n is too small)
initialize N and make segtree dependent on N
currently, segtree is dependent on n */

int n;
int st[4*mxN];

void update(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) { st[node] += x; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}
// for min segtree, remember to return INF instead of 0
int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return query(s, e, lo, mid, 2 * node + 1) + 
			query(s, e, mid + 1, hi, 2 * node + 2);
}

// lazy propagation
int lazy[4*mxN];

void push(int lo, int hi, int node) {
	if (lazy[node] == 0) return;
	// for non-sum segtree -> st[node] += lazy[node]
	st[node] += (hi - lo + 1) * lazy[node];
	if (lo != hi) {
		lazy[2 * node + 1] += lazy[node];
		lazy[2 * node + 2] += lazy[node];
	}
	lazy[node] = 0;
}
void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		lazy[node] = x;
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}
int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return query(s, e, lo, mid, 2 * node + 1) + 
			query(s, e, mid + 1, hi, 2 * node + 2);
}

// range set + range update
ll st[4*mxN], lazy[4*mxN];
bool reset[4*mxN];

void push(int lo, int hi, int node) {
	if (lazy[node] == 0 && reset[node] == 0) return;
	// for non-sum segtree -> st[node] += lazy[node]
	if (reset[node]) st[node] = (hi-lo+1) * lazy[node];
	else st[node] += (hi-lo+1) * lazy[node];
	if (lo != hi) {
		if (reset[node]) {
			lazy[2 * node + 1] = lazy[node];
			reset[2 * node + 1] = 1;
		} else lazy[2 * node + 1] += lazy[node];
		if (reset[node]) {
			lazy[2 * node + 2] = lazy[node];
			reset[2 * node + 2] = 1;
		} else lazy[2 * node + 2] += lazy[node];
	}
	lazy[node] = 0;
	reset[node] = 0;
}
void update_range(int s, int e, ll x, int lo=0, int hi=-1, int node=0, bool ad=0) {
	if (hi == -1) hi = n - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		lazy[node] = x;
		if (ad) reset[node] = 1;
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1, ad);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2, ad);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}
void set_range(int s, int e, ll x) {
	update_range(s,e,x,0,-1,0,1);
}
ll query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return query(s, e, lo, mid, 2 * node + 1) + 
			query(s, e, mid + 1, hi, 2 * node + 2);
}

/* returns pair<value,index>
can be used in min/max segtree */
void update(int i, pi x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) { st[node].f += x.f; st[node].s += x.s; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}
pi query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n - 1;
	if (hi < s || lo > e) return {0,0};
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return max(query(s, e, lo, mid, 2 * node + 1), 
			query(s, e, mid + 1, hi, 2 * node + 2));
}

/* smallest index in the range [l,r] such that st[idx] > x
to change to next_smaller
- (st[node] <= x) -> (st[node] >= x)
- (st[2 * node + 1] > x) -> (st[2 * node + 1] < x)
- change from max segtree to min segtree */
int next_larger(int l, int r, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n-1;
	if (hi < l || lo > r) return -1;
	if (l <= lo && hi <= r) {
		if (st[node <= x]) return -1;
		while (lo != hi) {
			int mid = (lo + hi) / 2;
			if (st[2 * node + 1] > x) {
				node = node * 2 + 1;
				hi = mid;
			} else {
				node = node * 2 + 2;
				lo = mid + 1;
			}
		}
		return lo;
	}
	int mid = (lo + hi) / 2;
	int ls = next_larger(l, r, x, lo, mid, 2 * node + 1);
	if (ls != -1) return ls;
	return next_larger(l, r, x, mid + 1, hi, 2 * node + 2);
}

/* largest index in range [l,r] such that st[idx] > x */
int last_larger(int l, int r, ll x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = n-1;
	if (hi < l || lo > r) return -1;
	if (l <= lo && hi <= r) {
		if (st[node] <= x) return -1;
		while (lo != hi) {
			int mid = (lo + hi) / 2;
			if (st[2 * node + 2] > x) {
				node = node * 2 + 2;
				lo = mid + 1;
			} else {
				node = node * 2 + 1;
				hi = mid;
			}
		}
		return lo;
	}
	int mid = (lo + hi) / 2;
	int rs = last_larger(l, r, x, mid + 1, hi, 2 * node + 2);
	if (rs != -1) return rs;
	return last_larger(l, r, x, lo, mid, 2 * node + 1);
}


struct pst {
	struct node {
		int v;
		node *l, *r;
		node() : node(0x3f3f3f3f) {}
		node(int v) : v(v), l(nullptr), r(nullptr) {}
	};

	int n;
	vector<node*> root;
	deque<node> buffer;

	pst(int n) : n(n) {
		root.push_back(build(0, n - 1)); 
	}

	node *build(int l, int r) {
		node *cur = new_node();
		if (l != r) {
		    int m = (l + r) / 2;
		    cur->l = build(l, m);
		    cur->r = build(m + 1, r);
		}
		return cur;
	}

	void copy(int pt, int t) {
		if ((int)(root.size()) <= t) {
			root.resize(t + 1);
		}
		root[t] = new_node(*root[pt]);
	}

	void upd(int pt, int t, int x, int v) {
		if ((int)(root.size()) <= t) {
	    	root.resize(t + 1);
		}
		root[t] = upd(root[pt], x, v, 0, n - 1);
	}

	node *upd(node *p, int x, int v, int l, int r) {
		node *cur = new_node(*p);
		if (l == r) {
	    	cur->v = v;
		} else {
		    int m = (l + r) / 2;
		    if (x <= m) {
	        	cur->l = upd(cur->l, x, v, l, m);
		    } else {
	        	cur->r = upd(cur->r, x, v, m + 1, r);
		    }
		    cur->v = min(cur->l->v, cur->r->v);
		}
		return cur;
	}
	int qry(int t, int x, int y) { 
		return qry(root[t], x, y, 0, n - 1);
	}

	int qry(node *p, int x, int y, int l, int r) {
		if (y < l || x > r) {
			// return based on min, max, sum
		    return 0x3f3f3f3f;
		} else if (x <= l && r <= y) {
	    	return p->v;
		} else {
		    int m = (l + r) / 2;
		    return min(qry(p->l, x, y, l, m), qry(p->r, x, y, m + 1, r));
		}
	}

	template<typename... Args>
	node *new_node(Args... args) {
		buffer.emplace_back(args...);
		return &buffer.back();
	}
};

pst st(n);


int main() {
	n = 100;
	for (int i = 0; i < n; i++) {
		update(i, i + 1); // add i+1 to the i-th number (initially 0)
	}
	cout << query(0, n - 1) << endl;
}
