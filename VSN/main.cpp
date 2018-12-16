/*input
4
3 0 0 -10 -10 0 0 10 0 0 -3 0 3
5 5 0 -4 -4 0 2 5 0 0 0 0 2
5 5 0 -4 -4 0 0 5 0 0 0 0 2
5 5 0 -4 -4 0 2 0 0 0 0 0 2
*/

//
//  main.cpp
//  VSN
//
//  Created by Nirmaljot Singh Bhasin on 03/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long int lli;

const double INF = 999999999;

struct Point {
	long double x, y, z;
};

Point P, Q, D, C;
long double r;

void transform() {
	P.x = P.x - C.x;
	P.y = P.y - C.y;
	P.z = P.z - C.z;

	Q.x = Q.x - C.x;
	Q.y = Q.y - C.y;
	Q.z = Q.z - C.z;

	C.x = C.y = C.z = 0;
}

long double sq(long double x) {
	return x * x;
}

long double distance(Point &p1, Point &p2) {
	return sqrt(sq(p2.x - p1.x) + sq(p2.y - p1.y) + sq(p2.z - p1.z));
}

bool isZero(long double x) {
	return (x > -0.0000000001 || x < +0.0000000001);
}

long double solve() {
	long double ux = Q.x - P.x;
	long double uy = Q.y - P.y;
	long double uz = Q.z - P.z;

	long double wx = P.x - C.x;
	long double wy = P.y - C.y;
	long double wz = P.z - C.z;

	long double fx = (uy * wz) - (wy * uz);
	long double fy = (ux * wz) - (wx * uz);
	long double fz = (ux * wy) - (wx * uy);

	long double gx = (wz * D.y - D.z * wy);
	long double gy = (wz * D.x - D.z * wx);
	long double gz = (wy * D.x - D.y * wx);

	long double u = sq(ux) + sq(uy) + sq(uz);
	long double f = sq(fx) + sq(fy) + sq(fz);
	long double g = sq(gx) + sq(gy) + sq(gz);
	long double d = sq(D.x) + sq(D.y) + sq(D.z);

	long double fg = fx * gx + fy * gy + fz * gz;
	long double ud = ux * D.x + uy * D.y + uz * D.z;

	long double A = g - sq(r) * d;
	long double B = 2 * (fg - sq(r) * ud);
	long double C = f - sq(r) * u;

	long double D = sqrt((B * B) - (4 * A * C));

	// cout << "A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;

	long double ans1 = INF, ans2 = INF;

	if (A != 0) {
		ans1 = (-B + D) / (2 * A);
		ans2 = (-B - D) / (2 * A);
	} else {
		ans1 = ans2 = -1 * (C / B);
	}

	if (ans2 < 0) {
		return ans1;
	} else if (ans1 < 0) {
		return ans2;
	} else {
		return min(ans1, ans2);
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cin >> P.x >> P.y >> P.z;
		cin >> Q.x >> Q.y >> Q.z;
		cin >> D.x >> D.y >> D.z;
		cin >> C.x >> C.y >> C.z;
		cin >> r;
		// transform();
		// cout << "P = (" << P.x << "," << P.y << "," << P.z << ")" << endl;
		// cout << "Q = (" << Q.x << "," << Q.y << "," << Q.z << ")" << endl;
		// cout << "D = (" << D.x << "," << D.y << "," << D.z << ")" << endl;
		// cout << "C = (" << C.x << "," << C.y << "," << C.z << ")" << endl;
		// cout << "R = " << r << endl;
		long double res = solve();
		printf("%.10Lf\n", res);
	}
	return 0;
}
