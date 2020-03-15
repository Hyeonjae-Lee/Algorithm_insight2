
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

int arr[10001];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i]; 
	}

	long long left = 0, right = 2000000000LL*10000LL, mid, midcheck=0, ans=0;
	if (n <= m) {
		cout << n;
		return 0;
	}
	while (left <= right) {
		mid = (right + left) / 2;
		ans = 0;
		long long begin, end;
		begin = end = 0;
		
		end = m;
		for (int i = 0; i < m; i++) {
			end += mid / arr[i];
		}

		begin = end;

		for (int i = 0; i < m; i++) {
			if (mid % arr[i] == 0)begin--;
		}
		
		begin++;

		if (n < begin) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else {

			for (int i = 0; i < m; i++) {
				if (mid % arr[i] == 0) {
					if (n == begin) {
						cout << i + 1;
						return 0;
					}begin++;
				}
			}
		}
	}
}