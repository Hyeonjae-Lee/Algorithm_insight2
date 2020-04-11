
/* 2015112119 이현재 */

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

multimap<string, vector<string>> MyMap;
map<string, string> mySet;
vector<string> user_id1;
vector<string> banned_id1;
vector<vector<string>> finalvec;

int banned_id_size;

bool check(string a, string b) {
	if (a.size() != b.size()) return false;
	else {
		for (int i = 0; i < b.length(); i++) {
			if (a[i] != b[i] && b[i] != '*') return false;
		}
		return true;
	}
}

int solve(vector<string> vec, int depth) {
	if (depth >= banned_id_size) {
		vector<vector<string>>::iterator iter;
		
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		iter = find(finalvec.begin(), finalvec.end(), vec);
		if (iter == finalvec.end()) {
			// 못찾은경우 -> 원소가 없으니까 벡터에 넣어주고 answer에 더해준다.
			finalvec.push_back(vec);
		}
		return 1;
	}
	int answer = 0;

	/*for (int i = MyMap.lower_bound(banned_id[depth]); i != MyMap.upper_bound(banned_id[depth]); i++)
		cout << i->second << endl;*/
	std::multimap<string, vector<string>>::iterator it;
	for (it = MyMap.equal_range(banned_id1[depth]).first; it != MyMap.equal_range(banned_id1[depth]).second; it++)
	{
		vector<string>::iterator iter;
		for (int j = 0; j < (*it).second.size(); j++) {//키값에 있는 벡터
			iter = find(vec.begin(), vec.end(), (*it).second[j]);
			if (iter == vec.end()) {
				// 못찾은경우 -> 원소가 없으니까 벡터에 넣어주고 answer에 더해준다.
				vec.push_back((*it).second[j]);
				answer += solve(vec, depth + 1);
				vec.pop_back();
			}
		}
	}
	return answer;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	banned_id_size = banned_id.size();
	banned_id1 = banned_id;
	user_id1 = user_id;

	vector<string> vec;

	for (int i = 0; i < banned_id.size(); i++) {
		vector<string> temp;
		for (int j = 0; j < user_id.size(); j++) {

			if (check(user_id[j], banned_id[i])) { // 아이디가 맞으면 
				
				temp.push_back(user_id[j]);
			}

			if (user_id[j].size() != banned_id[i].size()) {
				return false;
			}

			else {
				for (int i = 0; i < b.length(); i++) {
					if (a[i] != b[i] && b[i] != '*') return false;
				}
				return true;
			}
		}
		MyMap.insert({ banned_id[i] , temp });
	}

	answer += solve(vec, 0);
	
	sort(finalvec.begin(), finalvec.end());
	finalvec.erase(unique(finalvec.begin(), finalvec.end()), finalvec.end());

	return finalvec.size();
}

int main() {
	/*vector<string> user_id = { "frodo", "fradi","crodo","abc123","frodoc"};
	vector<string> banned_id = {"*rodo", "*rodo", "******"};*/

	vector<string> user_id = { "frodo", "fradi","crodo","abc123","frodoc" };
	vector<string> banned_id = { "******", "fr*d*", "c*odo" };

	cout << solution(user_id, banned_id);
}