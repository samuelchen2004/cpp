int n, arr[mxN], bit[mxN];

void update(int i, int x) {
	int j = i+1;
	for (; j < n+5; j += j&-j) {
		bit[j-1] += x;
	}
}
int get(int i) {
	int ret = 0, j = i+1;
	for (; j > 0; j -= j&-j) {
		ret += bit[j-1];
	}
	return ret;
}
int query(int i, int j) {
	return get(j) - (i ? get(i-1) : 0);
}
int main() {
	cin >> n;
	forr(i,0,n) {
		cin >> arr[i];
		update(i,arr[i]);
	}
	cout << query(0,n-1) << "\n";
}
