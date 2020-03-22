
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

int main() {
	string srr;
	cin >> srr;

	string Stack = "";
	string answer = "";

	int sum = 0;
	int temp1 = 1;
	int temp2 = 0;
	bool check = false;
	int finalsum = 0;

	if (srr.size() % 2 == 1) cout << 0;
	else {
		for (int i = 0; i < srr.size(); i++) {
			if (srr[i] == '(' || srr[i] == '[') {
				Stack.push_back(srr[i]);
				if (temp1 > 1) {
					temp2 += temp1;
					temp1 = 1;
				}
			}
			else {
				if (i - 1 >= 0 && Stack.back() == '(' && srr[i] == ')') {
					Stack.pop_back();

					if (Stack.empty()) {
						//비었다면
						if (temp2 == 0) {
							sum += temp1 * 2;
							temp2 = 0;
							temp1 = 1;
						}
						else {
							sum += temp2 + temp1;
							temp2 = 0;
							temp1 = 1;
							sum *= 2;
						}
					}
					else {
						temp1 *= 2;
					}
				}
				else if (i - 1 >= 0 && Stack.back() == '[' && srr[i] == ']') {
					Stack.pop_back();
					if (Stack.empty()) {
						//비었다면
						if (temp2 == 0) {
							sum += temp1 * 3;
							temp2 = 0;
							temp1 = 1;
						}
						else {
							sum = temp2 + temp1;
							temp2 = 0;
							temp1 = 1;
							sum *= 3;
						}

					}
					else {
						temp1 *= 3;
					}
				}
				else if(i - 1 >= 0 && Stack.back() == '[' && srr[i] == ')'){
					check = true;
					break;
				}
				else if (i - 1 >= 0 && Stack.back() == '(' && srr[i] == ']') {
					check = true;
					break;
				}
			}
		}

		if (check) cout << 0;
		else cout << sum;
	}
	
}