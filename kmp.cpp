str s, w;

void lps(str& w, vi& t) {
	t = vi(w.length());
	int i = 2, j = 0;
	t[0] = -1; t[1] = 0;
	while (i < w.length()) {
		if (w[i-1] == w[j]) {t[i] = j+1; i++; j++;}
		else if (j > 0) j = t[j];
		else {t[i] = 0; i++;}
	}
}
int kmp(str& s, str& w) {
	int m = 0, i = 0;
	vi t;
	lps(w, t);
	while (m+i < s.length()) {
		if (w[i] == s[m+i]) {
			i++;
			if (i == w.length()) return m;
		} else {
			m += i-t[i];
			if (i > 0) i = t[i];
		}
	}
	return s.length();
}
void solve() {
	cin >> s >> w;
	cout << kmp(s,w) << "\n"; // first occurrence of w in s
	cout << s.substr(kmp(s,w),w.length()) << "\n";
}





// benq's kmp

vi init_kmp(str s) {
	int N = sz(s); vi f(N+1); f[0] = -1;
	forr(i,1,N+1) {
		for (f[i] = f[i-1]; f[i] != -1 && s[f[i]] != s[i-1];) f[i] = f[f[i]];
		f[i]++;
	}
	return f;
}
// returns all occurrences of a in b
vi kmp(str a, str b) {
	vi f = init_kmp(a+"@"+b), ret;
	forr(i,sz(a),sz(b)+1) if (f[i+sz(a)+1] == sz(a)) ret.pb(i-sz(a));
	return ret;
}
