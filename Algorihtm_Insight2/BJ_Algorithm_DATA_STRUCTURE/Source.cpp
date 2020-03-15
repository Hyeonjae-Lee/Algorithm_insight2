/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n;

	cin >> n;
	int sum = 0;

	if (n == 1) cout << 1;
	else if (n == 2) cout << 4;
	else {
		if (n % 2 == 0) {
			int left = 1, right = 0;
			do {
				right = left + n * 2 - 2;
				sum += left + right;
				left = right + n * 2 - 2;
				
			} while (n -= 2);
		}
		else {
			int left = 1, right = 0;
			do {

				if (n == 1) {
					sum += left;
					break;
				}

				right = left + n * 2 - 2;
				sum += left + right;
				left = right + n * 2 - 2;

			} while (n -= 2);
		}
	}

	cout << sum;
}