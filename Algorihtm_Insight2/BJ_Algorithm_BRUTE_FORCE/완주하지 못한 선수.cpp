#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	while (!completion.empty()) {
		for (int i = 0; i < participant.size(); i++) {
			if (participant[i] == completion.back()) {
				
			}
		}
	}

	return answer;
}

int main() {

}