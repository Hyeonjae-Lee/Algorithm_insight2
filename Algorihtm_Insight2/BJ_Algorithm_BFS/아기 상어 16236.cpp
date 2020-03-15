
/* 2015112119 ������ */

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
				fishnum++;//�� ����� ��
			}
		}
	}

	queue<pair<pair<pi, pi>,int>> qu;
	qu.push(mp(mp(mp(2, 0), shark), 0));//����� ũ��, �ɸ� �ð�, ���� ����� ��ġ, ���� ����� ��
	
	int timesum = 0;
	
	while (!qu.empty()) {
		pi temp = qu.front().first.second;
		int tempsum = qu.front().first.first.first;//����� ũ��
		int tempts = qu.front().first.first.second;//�ɸ��ð�
		int fishsum = qu.front().second;//���� �����

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
				//���� ����� ����⸦ ã�Ҵ�.

				if (tempts2 < po.dis) {//�Ÿ��� ����� �༮�� �߰ߵǾ������
					po.x = temp2.first; po.y = temp2.second; po.dis = tempts2;
				}
				else if(tempts2 == po.dis) {//�Ÿ��� �������
					if (temp2.first == po.x) {//�� �Ʒ��� �������
						if (temp2.second < po.y) { 
							po.y = temp2.second;
						}
					}
					else if (temp2.first < po.x) {//�Ÿ��� ���� �� �Ʒ��� �ٸ����
						po.x = temp2.first; 
						po.y = temp2.second;
					}
				}
				continue;
			}

			//���� ����� ���� ã��
			if (temp2.first - 1 >= 0 && arr[temp2.first - 1][temp2.second] <= tempsum//ũ�Ⱑ ū ������ ���Դ´� 
				&& !visited[temp2.first-1][temp2.second]) {//���� ���°��
				qu2.push(Point(temp2.first - 1, temp2.second, tempts2 + 1));
				
				visited[temp2.first - 1][temp2.second] = true;
			}
			if (temp2.second - 1 >= 0 && arr[temp2.first][temp2.second - 1] <= tempsum 
				&& !visited[temp2.first][temp2.second - 1]) {//�������� ���°��
				qu2.push(Point(temp2.first, temp2.second - 1, tempts2 + 1));
				
				visited[temp2.first][temp2.second - 1] = true;
			}
			if (temp2.second + 1 < n && arr[temp2.first][temp2.second + 1] <= tempsum
				&& !visited[temp2.first][temp2.second + 1]) {//���������� ���°��
				qu2.push(Point(temp2.first, temp2.second + 1, tempts2 + 1));
				
				visited[temp2.first][temp2.second + 1] = true;
			}
			if (temp2.first + 1 < n && arr[temp2.first + 1][temp2.second] <= tempsum
				&& !visited[temp2.first + 1][temp2.second]) {//�Ʒ��� ���°��
				qu2.push(Point(temp2.first + 1, temp2.second, tempts2 + 1));
				
				visited[temp2.first + 1][temp2.second] = true;
			}

		}

		
		if (po.x==9999 && po.y == 9999 && po.dis == 9999) {
			break;
		}
		else if (fishsum + 1 == tempsum) {//����� ũ��� ���� ����� ���� ���ٸ�
			qu.push(mp(mp(mp(tempsum + 1, po.dis), mp(po.x, po.y)), 0));
			arr[po.x][po.y] = 0;
			//����� ũ��, �ɸ� �ð�, ���� ����� ��ġ, ���� ����� ��
		}
		else  {//����� ���� �ٸ����
			qu.push(mp(mp(mp(tempsum, po.dis), mp(po.x, po.y)), fishsum + 1));
			arr[po.x][po.y] = 0;
		}

	}

	cout << timesum;
}