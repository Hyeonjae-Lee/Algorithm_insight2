
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

long long int Arr[1000001];
vector<long long int> vec;
int main() {
	long long int n, need_tree, Max=0;

	cin >> n >> need_tree;

	for (int i = 0; i < n; i++) { cin >> Arr[i]; Max = Max > Arr[i] ? Max : Arr[i]; }

	long long int Left = 0, Right = Max, Mid = 0, Ans = 0;

	while (Left <= Right) {
		Ans = 0;
		Mid = (Left + Right) / 2;

		for (int i = 0; i < n; i++) {
			Ans += (Mid < Arr[i]) ? Arr[i] - Mid : 0;
		}
		if (Ans == need_tree) {
			vec.push_back(Mid);
			break;
		}else if (Ans > need_tree) {
			Left = Mid + 1;
			vec.push_back(Mid);
		}
		else {
			Right = Mid - 1;
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.back();
}