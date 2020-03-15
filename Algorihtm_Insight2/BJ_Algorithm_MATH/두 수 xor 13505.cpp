/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
using namespace std;
long long arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	long long mmax = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+n);

	cout << bitset<32>(arr[n - 1]) << endl;

	//cout << mmax;
}