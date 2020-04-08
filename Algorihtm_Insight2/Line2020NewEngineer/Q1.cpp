/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

int solution(string srr) {
	int answer = -1;

	int totalNum = 0, sum = 0;

	vector<char> vec;

	for (int i = 0; i < srr.size(); i++) {
		if (srr[i] == '{' || srr[i] == '(' || srr[i] == '[' || srr[i] == '<') {
			totalNum++;
			vec.push_back(srr[i]);
		}
		else if (srr[i] == '>' || srr[i] == ']' || srr[i] == ')' || srr[i] == '}') {
			totalNum++;
			vec.push_back(srr[i]);
			if (vec.size() > 1 && vec[vec.size() - 2] == '{' && vec[vec.size() - 1] == '}') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
			else if (vec.size() > 1 && vec[vec.size() - 2] == '[' && vec[vec.size() - 1] == ']') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
			else if (vec.size() > 1 && vec[vec.size() - 2] == '<' && vec[vec.size() - 1] == '>') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
			else if (vec.size() > 1 && vec[vec.size() - 2] == '(' && vec[vec.size() - 1] == ')') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
		}
	}

	if (totalNum == 0) return sum;
	else return -1;

	return answer;
}

int main() {
	string srr = ">_<";
	//cin >> srr;
	int totalNum = 0, sum = 0;

	vector<char> vec;

	for (int i = 0; i < srr.size(); i++) {
		if (srr[i] == '{' || srr[i] == '(' || srr[i] == '['|| srr[i] == '<' ) {
			totalNum++;
			vec.push_back(srr[i]);
		}
		else if (srr[i] == '>' || srr[i] == ']' || srr[i] == ')' || srr[i] == '}') {
			totalNum++;
			vec.push_back(srr[i]);
			if (vec.size() > 1 && vec[vec.size() - 2] == '{' && vec[vec.size() - 1] == '}') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			} else if (vec.size() > 1 && vec[vec.size() - 2] == '[' && vec[vec.size() - 1] == ']') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
			else if (vec.size() > 1 && vec[vec.size() - 2] == '<' && vec[vec.size() - 1] == '>') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
			else if (vec.size() > 1 && vec[vec.size() - 2] == '(' && vec[vec.size() - 1] == ')') {
				vec.pop_back();
				vec.pop_back();
				totalNum -= 2;
				sum++;
			}
		}
	}

	if (totalNum == 0) cout << sum;
	else cout << -1;
}