
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
#include <map>
#include <sstream>

using namespace std;


vector<string> solution(vector<string> directory, vector<string> command) {
	vector<string> answer;
	//stack����

	for (auto ele : command) {
		stringstream ss;
		string string1 = ele; 
		ss.str(string1); 
		string srr;
		vector <string> temp;

		while (ss >> srr) {
			temp.push_back(srr);
		}

		if (temp[0] == "mkdir") {
			//���� ����
			directory.push_back(temp[1]);
		}
		else if (temp[0] == "rm") {
			//����
			int value_to_remove = 2;
			directory.erase(remove(directory.begin(), directory.end(), temp[1]), directory.end());
		}
		else {

		}
	}

	return answer;
}

int main() {

}