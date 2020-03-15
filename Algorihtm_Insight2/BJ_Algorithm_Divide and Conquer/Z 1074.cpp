
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n, r, c;

int Count = 0;
bool flag = true;

void fun(int start, int end, int number) {
	if (number == 2) {
		if (flag) {
			if (start == r && end == c) {
				flag = false;
				return;
			}
			else Count++;
		}
		if (flag) {
			if (start == r && end + 1 == c) { flag = false; return; }
			else Count++;
		}
		if (flag) {
			if (start + 1 == r && end == c) {
				flag = false; return;
			}
			else Count++;
		}if (flag) {
			if (start + 1 == r && end + 1 == c) {
				flag = false; return;
			}
			else Count++;
		}
	}
	else {
		fun(start, end, number / 2);
		fun(start, end + number/2, number / 2);
		fun(start + number / 2, end, number / 2);
		fun(start + number / 2, end + number / 2, number / 2);
	}
}

int main() {

	cin >> n >> r >> c;

	fun(0, 0, pow(2, n));

	cout << Count;
}