/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;

int main() {
	string srr;

	cin >> srr;

	for (int i = 0; i < srr.size(); i++) {
		if (srr[i] == 'C' || srr[i] == 'A' || srr[i] == 'M' || srr[i] == 'B' || srr[i] == 'R' || srr[i] == 'I' || srr[i] == 'D' || srr[i] == 'G' || srr[i] == 'E') continue;
		else cout << srr[i];
	}
}