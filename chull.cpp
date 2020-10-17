int q = 1, n;
vector<PT> arr;

vector<PT> graham_scan(vector<PT> p) {
	sort(all(p));
	vector<PT> chull(p.size()+1);
	int idx = 0;
	forr(i,0,p.size()) {
		while (idx >= 2 && ccw(chull[idx - 2], chull[idx - 1], p[i])) idx--;
		chull[idx++] = p[i];
	}
	int half = idx;
	ford(i,p.size()-1,0) {
		while (idx > half && ccw(chull[idx - 2], chull[idx - 1], p[i])) idx--;
		chull[idx++] = p[i];
	}
	idx--;
	chull.resize(idx);
	return chull;
}
void solve() {
	cin >> n;
	forr(i,0,n) {PT p; cin >> p.x >> p.y; arr.pb(p);}
	vector<PT>chull = graham_scan(arr);
	trav(i,chull) cout << i.x << " " << i.y << "\n";
}
