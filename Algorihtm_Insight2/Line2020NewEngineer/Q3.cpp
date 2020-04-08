/* 2015112119 ������ */

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
		if (road[i] == '0') {//üũ����Ʈ �ϳ�

			if (vec.size() <= n) {
				//������ �� �Ƚ������
				vec.push_back(i);
			}
			else {
				//������ �� �������
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