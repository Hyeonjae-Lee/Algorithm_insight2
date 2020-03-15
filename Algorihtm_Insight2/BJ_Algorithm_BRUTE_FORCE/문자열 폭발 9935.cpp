/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int main() {
	string srr, bomb;

	cin >> srr>> bomb;

	vector<char> vec;

	int srr_lenght = srr.size();

	for (int i = 0; i < srr_lenght; i++) {
		vec.push_back(srr[i]);

		if (vec.size() >= bomb.size()) {
			bool check = true;
			for (int j = 0; j < bomb.size(); j++) {

				if (vec[vec.size() - bomb.size() + j] != bomb[j]) {
					check = false;
					break;
				}
			}

			if (check) {//있다는얘기
				int bomb_size = bomb.size();
				while (bomb_size--) vec.pop_back();
			}
		}
	}

	if (vec.size() > 0) for (auto ele : vec) cout << ele;
	else cout << "FRULA";
}