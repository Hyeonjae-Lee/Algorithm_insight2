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

int arr2[50], testcase;

bool check[50];

void fun(int depth, vector<int> arr, int start) {
	if (depth == 6) {
		for (auto ele : arr) cout << ele << " ";
		cout << endl;
	}
	else {
		for (int i = start; i < testcase; i++) {
			if (!check[i]) {
				check[i] = true;

				arr.push_back(arr2[i]);
				fun(depth + 1, arr, i);
				arr.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	while (~scanf_s("%d", &testcase)) {
		if (testcase == 0) break;
		//cin >> testcase && testcase != 0;
		memset(arr2, 0, sizeof(arr2));
		memset(check, false, sizeof(check));

		for (int i = 0; i < testcase; i++) cin >> arr2[i];

		vector<int> myvec;
		fun(0, myvec, 0);
		cout << '\n';
	}
}