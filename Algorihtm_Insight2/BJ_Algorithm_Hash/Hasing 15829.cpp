
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <queue>
#include <set>

using namespace std;
int m = 1234567891;

int main() {
	int n; 
	cin >> n;
	
	char srr;
	long long answer = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> srr;
		long long temp = srr - 96;
		
		for (int j = 0; j < i; j++) {
			temp *= 31;
			temp %= m;
		}
		answer = (answer%m + temp)%m;
	}
	cout << answer;
}