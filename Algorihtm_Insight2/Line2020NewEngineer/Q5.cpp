
/* 2015112119 ÀÌÇöÀç */

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

using namespace std;

bool desc(pair<string, int> a, pair<string, int> b){
	if (a.second != b.second) return (a.second > b.second);
	return a.first < b.first;
}

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
	vector<string> answer;
	map<string, int> myMap;

	for (int i = 0; i < dataSource.size(); i++) {
		bool flag = false;
		int sum = 0;

		for (int j = 1; j < dataSource[i].size(); j++) {

			for (int k = 0; k < tags.size(); k++) {
				if (dataSource[i][j] == tags[k]) {
					flag = true;
					sum++;
				}
			}
		}

		if (flag) myMap.insert({ dataSource[i][0], sum });
	}

	vector<pair<string, int>> tempvec;
	// copy key-value pairs from the map to the vector
	map<string, int> ::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		tempvec.push_back({ it->first, it->second});
	}

	sort(tempvec.begin(), tempvec.end(), desc);

	for (auto ele : tempvec) {
		answer.push_back(ele.first);
		if (answer.size() == 10) break;
	}

	return answer;
}

int main() {
	vector<vector<string>> dataSource = { {"doc1", "t1", "t2", "t3"} ,
	{"doc2", "t0", "t2", "t3" },
	{"doc3", "t1", "t6", "t7"},
	{"doc4", "t1", "t2", "t4"},
	{"doc5", "t6", "t100", "t8"} };

	vector<string> tags = { "t1", "t2", "t3" };
	solution(dataSource, tags);
}