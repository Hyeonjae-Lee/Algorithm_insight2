
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
#include <map>
#include <sstream>

using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
	vector<vector<string>> answer;
	set <vector<string>> mySet;
	map <string, string> myMap;

	for (int i = 0; i < transactions.size(); i++) {
		mySet.insert(transactions[i]);
	}

	for (int i = 0; i < snapshots.size(); i++) {
		myMap.insert({ snapshots[i][0], snapshots[i][1] });
	}

	for (auto ele : mySet) {
		
		string temp = myMap[ele[2]];//계좌 잔액 확인
		myMap.erase(ele[2]);//원소 삭제
		
		stringstream ss(temp);
		int n;
		ss >> n;

		stringstream ss1(ele[3]);
		int n2;
		ss1 >> n2;

		if (temp == "") n = 0;

		if (ele[1] == "SAVE") {
			myMap.insert({ ele[2] , to_string(n + n2) });
		}
		else {
			myMap.insert({ ele[2] , to_string(n - n2) });
		}
	}

	map <string, string>::iterator mm_iter;
	for (mm_iter = myMap.begin(); mm_iter != myMap.end(); mm_iter++) {
		
		vector<string> vec;
		vec.push_back(mm_iter->first);
		vec.push_back(mm_iter->second);
		answer.push_back(vec);
	}
	return answer;
}

int main() {
	vector<vector<string>> snapshots = { {"ACCOUNT1", "100"}, {"ACCOUNT2", "150" } };
	vector<vector<string>> transactions = { {"1", "SAVE", "ACCOUNT2", "100"}, {"2", "WITHDRAW", "ACCOUNT1", "50"}, {"1", "SAVE", "ACCOUNT2", "100"},{"4", "SAVE", "ACCOUNT3", "500"}, {"3", "WITHDRAW", "ACCOUNT2", "30"} };
	solution(snapshots, transactions);
}