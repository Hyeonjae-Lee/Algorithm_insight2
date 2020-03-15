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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, probNum, k=0;
	vector<int> arr;
	cin >> n;

	cin >> probNum;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin>>arr[i];

	if (probNum == 1) {
		cin >> k;
		do
		{
			if (k == 1) {
				for (auto ele : arr) cout << ele << " ";
				break;
			}
		} while (next_permutation(arr.begin(), arr.end()) && k--);
	}
	else {
		int x;
		vector<int> tempvec; tempvec.resize(n);
		for (int i = 0; i < n; i++) cin >> tempvec[i];
		do
		{
			if (arr==tempvec) {
				cout << k+1; break;
			}
			k++;
		} while (next_permutation(arr.begin(), arr.end()));
	}
}