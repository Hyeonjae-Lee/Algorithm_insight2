#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int dp[501][501];

	dp[0][0] = triangle[0][0];
	answer = dp[0][0];

	int check1 = 0, check2 = 0;
	if (triangle.size() > 1) {
		
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
				else if (j == triangle[i].size() - 1) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else {
					dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
				}
			}
		}

		for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
			answer = max(answer, dp[triangle.size() - 1][i]);
		}

	}

	return answer;
}

int main() {
	vector<vector<int>> triangle = { {7},{3,8}, {8,1,0},{2,7,4,4},{4,5,2,6,5} };
	solution(triangle);
}