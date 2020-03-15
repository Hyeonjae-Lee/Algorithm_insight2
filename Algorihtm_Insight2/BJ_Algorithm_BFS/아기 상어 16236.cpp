
/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
using namespace std;

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

int arr[21][21];
bool visited[21][21];

class Point {
public :
	int x=0, y=0, dis=0;

	Point(int a = 0,int b =0, int c= 0) : x(a), y(b), dis(c){}
};

int main() {
	int n, fishnum = 0;

	cin >> n;

	pi shark;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark = mp(i, j);
				arr[i][j] = 0;
			}
			else if (arr[i][j] > 0) {
				fishnum++;//총 물고기 수
			}
		}
	}

	queue<pair<pair<pi, pi>,int>> qu;
	qu.push(mp(mp(mp(2, 0), shark), 0));//상어의 크기, 걸린 시간, 지금 상어의 위치, 먹은 물고기 수
	
	int timesum = 0;
	
	while (!qu.empty()) {
		pi temp = qu.front().first.second;
		int tempsum = qu.front().first.first.first;//상어의 크기
		int tempts = qu.front().first.first.second;//걸린시간
		int fishsum = qu.front().second;//먹은 물고기

		qu.pop();

		timesum = tempts;

		if (fishnum == 0) {
			cout << tempts;
			return 0;
		}

		queue<Point> qu2;
		Point pointTemp;

		pointTemp.x = temp.first;
		pointTemp.y = temp.second;
		pointTemp.dis = tempts;

		qu2.push(pointTemp);

		memset(visited, false, sizeof(visited));

		Point po;
		po.x = 9999; po.y = 9999; po.dis = 9999;

		while (!qu2.empty()) {

			pi temp2 = mp(qu2.front().x, qu2.front().y);
			int tempts2 = qu2.front().dis;
			visited[temp2.first][temp2.second] = true;
			qu2.pop();

			if (arr[temp2.first][temp2.second] > 0 && tempsum > arr[temp2.first][temp2.second]) {
				//가장 가까운 물고기를 찾았다.

				if (tempts2 < po.dis) {//거리가 가까운 녀석이 발견되었을경우
					po.x = temp2.first; po.y = temp2.second; po.dis = tempts2;
				}
				else if(tempts2 == po.dis) {//거리가 같을경우
					if (temp2.first == po.x) {//위 아래가 같은경우
						if (temp2.second < po.y) { 
							po.y = temp2.second;
						}
					}
					else if (temp2.first < po.x) {//거리가 같고 위 아래가 다른경우
						po.x = temp2.first; 
						po.y = temp2.second;
					}
				}
				continue;
			}

			//가장 가까운 먹이 찾기
			if (temp2.first - 1 >= 0 && arr[temp2.first - 1][temp2.second] <= tempsum//크기가 큰 물고기는 못먹는다 
				&& !visited[temp2.first-1][temp2.second]) {//위로 가는경우
				qu2.push(Point(temp2.first - 1, temp2.second, tempts2 + 1));
				
				visited[temp2.first - 1][temp2.second] = true;
			}
			if (temp2.second - 1 >= 0 && arr[temp2.first][temp2.second - 1] <= tempsum 
				&& !visited[temp2.first][temp2.second - 1]) {//왼쪽으로 가는경우
				qu2.push(Point(temp2.first, temp2.second - 1, tempts2 + 1));
				
				visited[temp2.first][temp2.second - 1] = true;
			}
			if (temp2.second + 1 < n && arr[temp2.first][temp2.second + 1] <= tempsum
				&& !visited[temp2.first][temp2.second + 1]) {//오른쪽으로 가는경우
				qu2.push(Point(temp2.first, temp2.second + 1, tempts2 + 1));
				
				visited[temp2.first][temp2.second + 1] = true;
			}
			if (temp2.first + 1 < n && arr[temp2.first + 1][temp2.second] <= tempsum
				&& !visited[temp2.first + 1][temp2.second]) {//아래로 가는경우
				qu2.push(Point(temp2.first + 1, temp2.second, tempts2 + 1));
				
				visited[temp2.first + 1][temp2.second] = true;
			}

		}

		
		if (po.x==9999 && po.y == 9999 && po.dis == 9999) {
			break;
		}
		else if (fishsum + 1 == tempsum) {//상어의 크기와 먹은 물고기 수가 같다면
			qu.push(mp(mp(mp(tempsum + 1, po.dis), mp(po.x, po.y)), 0));
			arr[po.x][po.y] = 0;
			//상어의 크기, 걸린 시간, 지금 상어의 위치, 먹은 물고기 수
		}
		else  {//물고기 수가 다를경우
			qu.push(mp(mp(mp(tempsum, po.dis), mp(po.x, po.y)), fishsum + 1));
			arr[po.x][po.y] = 0;
		}

	}

	cout << timesum;
}