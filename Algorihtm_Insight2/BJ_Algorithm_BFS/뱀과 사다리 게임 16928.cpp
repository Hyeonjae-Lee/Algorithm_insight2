#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

int visited[102];

vector<int> sadari;
vector<int> snake;
int main() {

	int x, y;
	cin >> x >> y;
	int a, b;

	sadari.resize(102);

	for (int i = 0; i < x + y; i++) {
		cin >> a >> b;
		sadari[a] = b;
	}
	for (int i = 1; i <= 100; i++) visited[i] = 999999;

	queue<pi> qu;
	qu.push(mp(1, 0));
	visited[1] = 0;

	int finalsum = 9999999;

	while (!qu.empty()) {
		pi temp = qu.front();
		qu.pop();

		if (sadari[temp.first] != 0) qu.push(mp(sadari[temp.first], temp.second));
		else {
			for (int i = 1; i <= 6; i++) {

				if (temp.first + i < 101 && visited[temp.first + i] > temp.second + 1) {
					
					visited[temp.first + i] = temp.second + 1;
					qu.push(mp(temp.first + i, temp.second + 1));
					
				}
			}
		}
	}

	cout << visited[100];
}