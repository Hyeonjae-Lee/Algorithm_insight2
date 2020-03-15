
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

char arr[10000][10000];

void initfun(int start, int end, int number) {
	for (int i = start; i < start + number; i++) for (int j = end; j < end + 2*number - 1; j++) arr[i][j] = ' ';
}

void fun(int start, int end, int number) {
	if (number == 3) {
		arr[start][end + 2] = '*';
		arr[start + 1][end + 1] = '*'; arr[start + 1][end + 3] = '*';
		for (int i = end; i < end + 5; i++) arr[start + 2][i] = '*';
	}
	else {
		fun(start, end + number / 2, number / 2);
		fun(start + number/2, end, number / 2);
		fun(start + number/2, end + number, number / 2);
	}
}


int main() {
	int number;

	cin >> number;

	initfun(0, 0, number);
	fun(0, 0, number);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number*2 - 1; j++) cout << arr[i][j];
		cout << '\n';
	}
}