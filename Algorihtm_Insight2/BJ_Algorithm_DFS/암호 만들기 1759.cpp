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

int L, C;
char arr[15];
bool check[15];

vector<string> vec;

void fun(int start, int depth, string srr, int mo, int ja) {
	if (depth == L) {
		if(mo>=1 && ja>=2) vec.push_back(srr);
	}
	else {
		for (int i = 0; i < C; i++) {

			if (!check[i]) {//아직 도착하지 않았을 경우
				check[i] = true;

				if (arr[i] == 'a' || arr[i] == 'u' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'e') {
					if(srr=="") fun(i, depth + 1, srr + arr[i], mo + 1, ja);
					else if(srr[srr.length()-1] < arr[i])
						fun(i, depth + 1, srr + arr[i], mo + 1, ja);
				}
				else {
					if(srr=="") fun(i, depth + 1, srr + arr[i], mo, ja + 1);
					else if (srr[srr.length() - 1] < arr[i])
						fun(i, depth + 1, srr + arr[i], mo, ja + 1);
				}

				check[i] = false;
			}
		}
	}
}

int main() {
	
	cin >> L >> C;

	for (int i = 0; i < C; i++) cin >> arr[i];

	memset(check, false, sizeof(check));

	fun(0, 0, "", 0, 0);

	sort(vec.begin(), vec.end());

	for (auto ele : vec) cout << ele << '\n';
}