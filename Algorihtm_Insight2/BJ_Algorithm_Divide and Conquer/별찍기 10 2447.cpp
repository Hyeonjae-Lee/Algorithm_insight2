
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

char arr[4000][4000];

void initfun(int start, int end, int number) {
	for (int i = start; i < start + number; i++) {
		for (int j = end; j < end + number * 2 - 1; j -= 2) arr[i][j] = ' ';
	}
}

void fun(int start, int end, int number) {
	if (number == 3) {
		for (int i = start; i < start + number; i++) {
			for (int j = end; j < end + number; j++) {
				if (i == start + 1 && j == end + 1) arr[i][j] = ' ';
				else arr[i][j] = '*';
			}
		}
	}
	else {
		for (int i = start; i < start + number; i += number / 3) {
			for (int j = end; j < end + number; j += number / 3) {
				if (i == start + number / 3 && j == end + number / 3) initfun(i, j, number / 3);
				else fun(i, j, number / 3);
			}
		}
	}
}


int main() {
	int number;

	cin >> number;

	fun(0, 0, number);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) cout << arr[i][j];
		cout << '\n';
	}
}
