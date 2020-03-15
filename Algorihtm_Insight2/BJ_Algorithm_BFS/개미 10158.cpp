/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

int vx[4] = { 1, -1, -1, -1 };
int vy[4] = { 1, 1, -1, 1 };

int main() {
	int w, h, x, y, t;

	cin >> w >> h >> x >> y;
	cin >> t;

	int tx = 1, ty = 1;



	while (t--) {
		if (x == w || y == h || x==0 || y == 0) {//부딫친 경우
			if (x == w && y == h) {
				tx = ty = -1;
			}
			else if (x == 0 && y == h) {
				tx = 1; ty = -1;
			}
			else if (x == 0 && y == 0) {
				tx = 1; ty = 1;
			}
			else if (x == w && y == 0) { tx = -1; ty = 1; }
			else {
				if (tx == 1 && ty == 1) {
					if (y == h) ty = -1;
					else if (x == w) tx = -1;
				}
				else if (tx == -1 && ty == 1) {
					if (y == h) ty = -1;
					else if (x == 0) tx = 1;
				}
				else if (tx == 1 && ty == -1) {
					if (y == 0) ty = 1;
					else if (x == w) tx = -1;
				}
				else if (tx == -1 && ty == -1) {
					if (y == 0) ty = 1;
					else if (x == 0) tx = 1;
				}
			}
		}
		x += tx; y += ty;
	}

	cout << x << " " << y;
}