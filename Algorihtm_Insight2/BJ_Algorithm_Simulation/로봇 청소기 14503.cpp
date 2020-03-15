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

int arr[51][51];
int check[51][51];
int sum = 0;

class Cleaner {
public:
	int r, c, d;
	Cleaner(int a = 0, int b = 0, int c = 0) : r(a), c(b), d(c) {}
};


void dfs(Cleaner a) {

	if (a.r < 0 || a.c < 0 || a.r > 50 || a.c > 50) return;

	if (!check[a.r][a.c])
	{
		//�������� �ʾ��� ���
		sum++;
		check[a.r][a.c] = 2;

	}//���� ��ġ�� û���Ѵ�.

	if (a.d == 0) {//up
		if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c]) && arr[a.r + 1][a.c]) {
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
			return;
		}
		else if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c])) {
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��� ����
			dfs(Cleaner(a.r + 1, a.c, a.d));
		}
		else if (!check[a.r][a.c - 1]) {//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�
			dfs(Cleaner(a.r, a.c - 1, 3));
		}
		else if (check[a.r][a.c - 1]) {//���� ���⿡ û���� ������ ���ٸ�,
			dfs(Cleaner(a.r, a.c, 3));
		}
	}
	else if (a.d == 1) {//right
		if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c]) && arr[a.r][a.c - 1]) {
			return;
		}
		else if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c])) {
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��� ����
			dfs(Cleaner(a.r, a.c - 1, a.d));
		}
		else if (!check[a.r - 1][a.c]) {
			//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ� �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			dfs(Cleaner(a.r - 1, a.c, 0));
		}
		else if (check[a.r - 1][a.c]) {//���� ���⿡ û���� ������ ���ٸ�,
			dfs(Cleaner(a.r, a.c, 0));
		}

	}
	else if (a.d == 2) {//down
		if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c]) && arr[a.r - 1][a.c]) {
			return;
		}
		else if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c])) {//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
			dfs(Cleaner(a.r - 1, a.c, a.d));
		}
		else if (!check[a.r][a.c + 1]) {//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�
			dfs(Cleaner(a.r, a.c + 1, 1));
		}
		else if (check[a.r][a.c + 1]) {//���� ���⿡ û���� ������ ���ٸ�,
			dfs(Cleaner(a.r, a.c, 1));
		}
	}
	else {//left
		if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c]) && arr[a.r][a.c + 1]) {
			return;
		}
		else if ((arr[a.r][a.c - 1] || check[a.r][a.c - 1]) && (arr[a.r][a.c + 1] || check[a.r][a.c + 1]) &&
			(arr[a.r - 1][a.c] || check[a.r - 1][a.c]) && (arr[a.r + 1][a.c] || check[a.r + 1][a.c])) {
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
			dfs(Cleaner(a.r, a.c + 1, a.d));
		}
		else if (!check[a.r + 1][a.c]) {
			//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ� �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			dfs(Cleaner(a.r + 1, a.c, 2));
		}
		else if (check[a.r + 1][a.c]) {//���� ���⿡ û���� ������ ���ٸ�,
			dfs(Cleaner(a.r, a.c, 2));
		}
	}
}

int main() {
	int n, m, r, c, d;

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 1) check[i][j] = true;
	}
	Cleaner cleaner(r, c, d);

	dfs(cleaner);

	cout << sum;
}