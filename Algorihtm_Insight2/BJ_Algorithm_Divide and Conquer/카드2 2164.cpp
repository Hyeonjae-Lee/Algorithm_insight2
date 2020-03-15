
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	queue<int> qu;

	for (int i = 0; i < n; i++) qu.push(i + 1);

	while (qu.size() != 1) {
		qu.pop();
		int x = qu.front();
		qu.pop();
		qu.push(x);
	}

	cout << qu.back();
}