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

int main() {
	string srr;
	cin >> srr;

	string temp = srr;
	string answer = "";
	vector<string> vec;

	int checkPoint = 0;

	for (int i = 0; i < srr.size(); i++) {	
	
		if (srr[i] != '+' && srr[i] != '/' && srr[i] != '*' && srr[i] != ')' && srr[i] != '(' && srr[i] != '-') {
			//���ĺ��ΰ��
			
			cout << srr[i];
			if (answer.size() > 0 && (answer.back() == '*' || answer.back() == '/')) {
				//answer�� ���� �����鼭 *,/�϶�
				cout << answer.back();
				answer.pop_back();
			}
			else if (answer.size() > 0 && (answer.back() == '+' || answer.back() == '-')) {
				if (i + 1 < srr.size() && (srr[i + 1] == '*' || srr[i + 1] == '/')) {
					
				}
				else {
					cout << answer.back();
					answer.pop_back();
				}
			}
		}
		else {
			//���ĺ��� �ƴѰ��
			if (srr[i] == '*' || srr[i] == '/') {
				while (!answer.empty() && answer.back() != '(' && answer.back() != '+' && answer.back() != '-') {
					cout << answer.back();
					answer.pop_back();
				}
				answer.push_back(srr[i]);
			}
			else if (srr[i] == '-' || srr[i] == '+') {
				if (answer.size() > 0) {
					while (!answer.empty() && answer.back() != '(' ) {
						cout << answer.back();
						answer.pop_back();
					}
				}
				answer.push_back(srr[i]);
			}
			else if (srr[i] == '(') {
				answer.push_back(srr[i]);
			}
			else if (srr[i] == ')') {
				if ((answer.back() == '(')) {
					//answer�� ���� �����鼭 ( �϶�
					answer.pop_back();// ( pop
				}
				else {
					while (!answer.empty() && answer.back() != '(') {
						cout << answer.back();
						answer.pop_back();
					}
					answer.pop_back();
				}
			}
		}
	}

	while (!answer.empty()) {
		if (answer.back() != '(' || answer.back() != ')') cout << answer.back();
		answer.pop_back();
	}
}