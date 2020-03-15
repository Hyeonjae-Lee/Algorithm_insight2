
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

vector<int> vec;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	for (int i = 0; i < moves.size(); i++) {
		
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i]-1] > 0) {
				vec.push_back(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}

		if (vec.size() > 1) {
			if (vec[vec.size() - 1] == vec[vec.size() - 2]) {
				vec.pop_back();
				vec.pop_back();
				answer+=2;
			}
		}
	}

	return answer;
}


int main() {

	vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	solution(board, moves);
}