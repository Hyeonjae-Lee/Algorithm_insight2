/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;


int solution(string answer_sheet, vector<string> sheets) {
	int answer = -1;

	for (int i = 0; i < sheets.size(); i++) {
		for (int j = i + 1; j < sheets.size(); j++) {
			int ques = 0, lineQues = 0, finalQues = 0;//ques는 의심문항, liques = 연속된
			for (int k = 0; k < answer_sheet.size(); k++) {
				if (sheets[i][k] == sheets[j][k] && answer_sheet[k] != sheets[i][k]) {
					//의심문항
					ques++;
					lineQues++;
				}
				else {
					finalQues = max(finalQues, lineQues);
					lineQues = 0;
				}
			}

			finalQues = max(finalQues, lineQues);
			lineQues = 0;

			answer = max(answer, ques + finalQues*finalQues);
			//총 의심 문항의 수 + (가장 긴 연속된 의심 문항의 수)2
		}
	}

	return answer;
}

int main() {
	string answer_sheet = "24551";
	vector<string> sheets = { "24553", "24553", "24553", "24553" };
	cout << solution(answer_sheet, sheets);
}