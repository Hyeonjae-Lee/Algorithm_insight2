/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
using namespace std;

int main() {
	int testcase, Sum=0, tx;
	cin >> testcase;

	deque<int> qu;

	for (int i = 0; i < testcase; i++) {
		cin >> tx;
		qu.push_back(tx);
	}

	while (qu.size()>2) {
		int j;
		for (j = 1; j < qu.size(); j++) {
			if (qu.front() < qu[j]) {
				Sum++;
				qu.pop_front();
				break;
			}
			else Sum++;
		}

		if(j==qu.size()) qu.pop_front();
	}

	Sum++;

	cout << Sum;
}