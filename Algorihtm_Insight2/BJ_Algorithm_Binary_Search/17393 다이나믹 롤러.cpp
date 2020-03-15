
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

long long int A[500001];
long long int B[500001];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	for (int i = 1; i < n; i++) {
		if (i == n - 1) {
			cout << 0; break;
		}

		int temp = upper_bound(B + i, B + n, A[i]) - (B + i + 1);

		cout << temp << " ";
	}
}