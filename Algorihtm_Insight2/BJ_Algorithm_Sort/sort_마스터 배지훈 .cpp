/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
	int max1 = 0, x, n;
	cin >> n;
	while (n--) {
		cin >> x;
		max1 = max(max1, x);
	}
	cout << max1;
}