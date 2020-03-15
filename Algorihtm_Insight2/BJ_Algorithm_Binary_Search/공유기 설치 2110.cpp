
/* 2015112119 이현재 */

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
	int n, c, model[200001];

	cin >> n >> c;

	for (int i = 0; i < n; i++) cin >> model[i];

	sort(model, model + n);

	int d = 1, Sum=0, Mindistance;

	int Left = 1, Right = model[n - 1];
	int Mid, Ans=1;
	while (Left <= Right) {
		Mid = (Left + Right)/2;
		Mindistance = 999999;
		int check = 0; Sum = 1;

		for (int i = 1; i < n; i++) {
			
			if (model[i] - model[check] >= Mid) {//Mid보다 길경우
				Sum++;
				check = i;
			}

		}

		if (Sum >= c) {
			if (Ans < Mid) Ans = Mid;
			Left = Mid + 1;
		}
		else {
			Right = Mid - 1;
		}

	}

	cout << Ans;
}