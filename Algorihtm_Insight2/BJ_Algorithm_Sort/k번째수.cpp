#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tempanswer;
	int length = commands.size();

	for (int i = 0; i < length; i++) {
		tempanswer.clear();
		for (int j = commands[i][0]-1; j < commands[i][1]; j++) {
			tempanswer.push_back(array[j]);
		}

		sort(tempanswer.begin(), tempanswer.end());
		answer.push_back(tempanswer[commands[i][2]-1]);
	}

	return answer;
}

int main() {
	vector<int> arr = { 1,5,2,6,3,7,4 };
	vector<vector<int>> arr2 = { {2,5,3},{4,4,1},{1,7,3} };

	solution(arr, arr2);

}