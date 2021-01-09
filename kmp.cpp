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
	cout << kmp(s,w) << "\n";
	cout << s.substr(kmp(s,w),w.length()) << "\n";
}