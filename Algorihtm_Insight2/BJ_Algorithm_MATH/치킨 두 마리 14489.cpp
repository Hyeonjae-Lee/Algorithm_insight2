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
	int a, b, c;

	cin >> a >> b >> c;

	if (a + b >= 2 * c) cout << a + b - (2 * c);
	else cout << a + b;
}