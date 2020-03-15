/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 1; i <= s.size()/2; i++) {

		string srr = s;
		string temp = "";

		while (!srr.empty()) {
			string tempsrr = "";

			for (int j = 0; j < i; j++) tempsrr += srr[j];


		}


	}




	return answer;
}

int main() {
	cout << solution("abcabcabcabcdededededede");
}