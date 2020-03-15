/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

int main() {
	long long int w, h, p, q, t;

	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	long long int tx = t + p, ty = t + q;
	long long int ansx = 0, ansy = 0;

	if (tx % w == 0 && (tx / w) % 2 == 0) ansx = 0;
	else if (tx % w == 0 && (tx / w) % 2 == 1) ansx = w;
	else if ((tx / w) % 2 == 0) ansx = tx % w;
	else ansx = w - tx % w;

	if (ty % h == 0 && (ty / h) % 2 == 0) ansy = 0;
	else if (ty % h == 0 && (ty / h) % 2 == 1) ansy = h;
	else if ((ty / h) % 2 == 0)ansy = ty % h;
	else ansy = h - ty % h;

	cout << ansx << " " << ansy;
}

