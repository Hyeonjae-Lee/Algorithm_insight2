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

int main() {
	int n, sum = 0;

	cin >> n;
	sum = 1;
	
	//n=5
	while (n>0) {
		
		int temp = n;

		while (temp > 0) {
			if (temp % 10 > 0) {
				break;
			}
			temp /= 10;
		}

		sum *= temp;

		while (sum > 0) {
			if (sum % 10 > 0) {
				break;
			}
			sum /= 10;
		}

		sum %= 100000; n--;
	}

	cout << sum%10;
}