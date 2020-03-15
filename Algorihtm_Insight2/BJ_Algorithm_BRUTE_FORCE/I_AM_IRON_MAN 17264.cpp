/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
	int n, p, w, l, g, goal = 0;
	string player;
	char checkwin;
	vector<string> winPlayer;
	vector<string> losePlayer;

	vector<string> players;

	cin >> n >> p >> w >> l >> g;

	while (p--) {
		cin >> player >> checkwin;
		if (checkwin == 'W') winPlayer.push_back(player);
		else losePlayer.push_back(player);
	}

	while (n--) {
		cin >> player;

		if (find(winPlayer.begin(), winPlayer.end(), player) != winPlayer.end()) {//여기에 찾았다면
			goal += w;
		}
		else {
			goal -= l;
			if (goal < 0) goal = 0;
		}
		if (goal >= g) {
			cout << "I AM NOT IRONMAN!!";
			return 0;
		}
	}

	cout << "I AM IRONMAN!!";
}