
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

int solution(vector<int> stones, int k) {
	int answer = 0;

	while (1) {
		int ans = 0;
		
		for (int i = 0; i < stones.size(); i++) {
			if (ans >= k) {				
				return answer;
				break;
			}
			if (stones[i] > 0) {
				stones[i]--;
				ans = 0;
			}
			else {
				ans++;
			}
		}
		answer++;
	}

	return answer;
}


int main() {

}