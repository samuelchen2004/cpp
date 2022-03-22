const int N = 10;
typedef array<array<mi, N>, N> mat;

mat init(vector<vi> v) {
	mat a;
	forr(i,0,v.size()) forr(j,0,v[0].size()) a[i][j] = v[i][j];
	return a;
}
mat operator *(const mat &a, const mat &b) {
	mat c;
	forr(i,0,N) forr(j,0,N) c[i][j] = 0;
	forr(i,0,N) forr(j,0,N) forr(k,0,N) c[i][j] += a[i][k]*b[k][j];
	return c;
}
mat mpow(mat a, ll p, mat b) {
	while (p) {
		if (p % 2) b = a*b;
		a = a*a;
		p /= 2;
	}
	return b;
}
