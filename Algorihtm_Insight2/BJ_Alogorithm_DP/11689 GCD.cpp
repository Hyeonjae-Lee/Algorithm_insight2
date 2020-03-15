/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int phi(int n) {
	int result = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			result -= result / i;
		}
	}

	if (n > 1) result -= result / n;

	return result;
}


int main() {

	long long n;

	scanf_s("%lli", &n);

	int result = n;

	

	cout << result;
}