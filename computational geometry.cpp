const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????
struct PT {
	double x,y;
	double length() {return sqrt(x*x+y*y);}
	// normalize the vector to unit length; return -1 if the vector is 0
	int normalize() {
		double l = length();
		if(fabs(l) < EPS) return -1;
		x /= l; y /= l;
		return 0;
	}
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
	PT operator*(double sc)	{
		PT r;
		r.x = x*sc; r.y = y*sc;
		return r;
	}
};
bool operator<(const PT& a,const PT& b) {
	if (fabs(a.x-b.x) < EPS) return (a.y < b.y);
	return a.x<b.x;
}
// the distance between two points
double dist(PT& a, PT& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
// the inner product of two vectors
double dot(PT& a, PT& b) {
	return(a.x*b.x+a.y*b.y);
}
double cross(PT& a, PT& b) {
	return (a.x*b.y-a.y*b.x);
}
