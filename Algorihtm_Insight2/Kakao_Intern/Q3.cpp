
/* 2015112119 ������ */

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

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;

	for (int i = 0; i < banned_id.size(); i++) {
		//�����
		for (int k = 0; k < user_id.size(); k++) {
			//����

			if (banned_id[i].size() != user_id[k].size()) continue;//���� ���� �ٸ���� 
			bool falg = false;
			for (int j = 0; j < banned_id[i].size(); j++) {
				
				if (banned_id[i][j] == '*') continue;
				else if (banned_id[i][j] != user_id[k][j]) {
					//�����������
					falg = true;
					break;
				}
			}

			if (falg) continue;//�����������
			else {
				answer++;
				break;
			}
		}
	}

	return answer;
}

int main() {

	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "abc1**" };

	solution(user_id, banned_id);
}