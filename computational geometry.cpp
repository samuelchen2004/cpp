const ld PI = 2.0*acos(0.0);
const ld EPS = 1e-9; //too small/big?????
struct PT {
	ld x,y;
	ld length() {return sqrt(x*x+y*y);}
	// normalize the vector to unit length; return -1 if the vector is 0
	int normalize() {
		ld l = length();
		if(fabs(l) < EPS) return -1;
		x /= l; y /= l;
		return 0;
	}
	// don't forget to include PT p1 = {operator} instead of just {operator}!
	PT operator-(PT a) {
		PT r;
		r.x = x-a.x; r.y = y-a.y;
		return r;
	}
	PT operator+(PT a) {
		PT r;
		r.x = x+a.x; r.y = y+a.y;
		return r;
	}
	PT operator*(ld sc)	{
		PT r;
		r.x = x*sc; r.y = y*sc;
		return r;
	}
};
bool operator<(const PT& a,const PT& b) {
	if (fabs(a.x-b.x) < EPS) return (a.y < b.y);
	return (a.x < b.x);
}
// the distance between two points
ld dist(PT& a, PT& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
// the inner product of two vectors
ld dot(PT& a, PT& b) {
	return(a.x*b.x+a.y*b.y);
}
ld cross(PT& a, PT& b) {
	return (a.x*b.y-a.y*b.x);
}
bool cw(PT a, PT b, PT c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(PT a, PT b, PT c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
int intersection(PT p1, PT p2, PT p3, PT p4, PT &r) {
	ld d = (p4.y-p3.y)*(p2.x-p1.x) - (p4.x-p3.x)*(p2.y-p1.y);
	if (fabs(d) < EPS) return -1;
	ld ua, ub;
	ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
	ua /= d;
	// ub = (p2.x-p1.x)*(p1.y-p3.y) - (p2.y-p1.y)*(p1.x-p3.x);
	// ub /= d;
	r = p1 + (p2-p1)*ua;
	return 0;
}
