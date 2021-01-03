bool sort0(const vi& v1, const vi& v2) {return v1[0] < v2[0];}
bool sort1(const vi& v1, const vi& v2) {return v1[1] < v2[1];}
void compress() {
	vector<vi> v;
	forr(i,0,n) v.pb(vi{arr[i],i});
	sort(v.begin(),v.end(),sort0);
	unordered_map<int,int> m;
	int curr = 0;
	forr(i,0,v.size()) {
		if (i && v[i][0] != v[i-1][0]) curr++;
		m[v[i][0]] = curr;
	}
	sort(v.begin(),v.end(),sort1);
	forr(i,0,v.size()) arr[i] = m[v[i][0]];
}
