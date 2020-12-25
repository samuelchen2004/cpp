pair<vi,vi> partition(vi &v) {
	int sum = accumulate(all(v),0);
	if (sum % 2) return {vi(),vi()};
	sum /= 2;
	bitset<x> pos[v.size()+5];
	pos[0][0] = 1;
	forr(i,0,v.size()) pos[i+1] = pos[i] | pos[i] << v[i];
	if (!pos[v.size()][sum]) return {vi(),vi()};
	int idx = v.size();
	ford(i,v.size(),0) {
		if (sum >= v[i] && pos[i][sum-v[i]]) sum -= v[i];
		else swap(v[i],v[--idx]);
	}
	return {vi(v.begin(),v.begin()+idx),vi(v.begin()+idx,v.end())};
}
