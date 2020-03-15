
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

int A[2200][2200];
int Minus = 0, zero = 0, Plus = 0;

inline int solve(int x, int y, int n) {

	try {

		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (A[x][y] != A[i][j]) {

					throw - 1;
				}
			}
		}

		if (A[x][y] == 0) zero++;
		else if (A[x][y] == 1) Plus++;
		else Minus++;

	}
	catch (int e) {
		//모든 원소가 같지 않다.

		int temp = n / 3;

		solve(x, y, temp);
		solve(x, y + temp, temp);
		solve(x, y + 2 * temp, temp);

		solve(x + temp, y, temp);
		solve(x + temp, y + temp, temp);
		solve(x + temp, y + 2 * temp, temp);

		solve(x + 2 * temp, y, temp);
		solve(x + 2 * temp, y + temp, temp);
		solve(x + 2 * temp, y + 2 * temp, temp);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int number;

	cin >> number;

	for (int i = 0; i < number; i++) for (int j = 0; j < number; j++) cin >> A[i][j];

	int startx = 0, starty = 0, temp = number / 3;

	solve(0, 0, number);

	cout << Minus << '\n' << zero << '\n' << Plus;
}