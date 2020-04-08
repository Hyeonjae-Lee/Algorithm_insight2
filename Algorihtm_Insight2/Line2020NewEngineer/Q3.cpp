/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <queue>
#include <set>

using namespace std;

int solution(string road, int n) {
	int answer = -1;

	int start = 0;
	int roadLength = 0;

	deque<int> vec;

	for (int i = 0; i < road.size(); i++) {
		if (road[i] == '0') {//체크포인트 하나

			if (vec.size() <= n) {
				//세개를 다 안썼을경우
				vec.push_back(i);
			}
			else {
				//세개를 다 썻을경우
				roadLength = vec.back() - start;
				start = vec.front() + 1;
				vec.pop_front();
				vec.push_back(i);

				answer = max(answer, roadLength);
			}
		}
	}

	if (start == 0 && answer == -1) return road.size();
	return answer;
}


int main() {
	string road = "001100";
	int n = 5;
	cout << solution(road, n);
}