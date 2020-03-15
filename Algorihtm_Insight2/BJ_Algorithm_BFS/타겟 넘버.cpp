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

vector<int> num;
int target1;
int answer1 = 0;
int DFS(int sum, int start, int end) {

	if (start == end) {
		if (target1 == sum) return 1;

		return 0;
	}

	answer1 = DFS(sum + num[start], start + 1, end) + DFS(sum - num[start], start + 1, end);

	return answer1;
}


int solution(vector<int> numbers, int target) {
	int answer = 0;

	num = numbers;
	target1 = target;
	answer = DFS(0, 0, numbers.size());

	return answer;
}

int main() {
	string srr = "aaaaabbbb";

	srr.erase(0, 5);

	vector<int> temp = { 1,1,1,1,1 };
	cout << solution(temp, 3);

}