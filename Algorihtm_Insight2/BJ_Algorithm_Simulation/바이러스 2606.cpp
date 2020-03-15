#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[101];

int main() {

	int compu_num, quest_num, a, b;

	cin >> compu_num;
	cin >> quest_num;

	vector<vector<int>> vec;

	vec.resize(compu_num);

	for (int i = 0; i < quest_num; i++) {
		cin >> a >> b;

		vec[a - 1].push_back(b - 1);
		vec[b - 1].push_back(a - 1);
	}


	queue<int> qu;
	qu.push(0);

	visited[0] = true;
	int sum = 0;

	while (!qu.empty()) {
		int temp = qu.front();
		qu.pop();

		for (int i = 0; i < vec[temp].size(); i++) {
			if (!visited[vec[temp][i]]) {
				//방문하지 않은 점일 경우
				qu.push(vec[temp][i]);
				sum++;
				visited[vec[temp][i]] = true;
			}
		}
	}

	cout << sum;
}