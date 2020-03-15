
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

vector<long long> arr(200001);

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (long long i = 0; i < room_number.size(); i++) {
		if (!arr[room_number[i]]) {
			answer.push_back(room_number[i]);
			arr[room_number[i]]++;
		}
		else {
			long long tempx = room_number[i];
			do {
				tempx++;
			} while (arr[tempx]);
			answer.push_back(room_number[tempx]);
			arr[tempx]++;
		}
	}
	return answer;
}

int main() {
	long long k = 10;
	vector<long long> room_number = { 1,3,4,1,3,1 };

	solution(k, room_number);
}