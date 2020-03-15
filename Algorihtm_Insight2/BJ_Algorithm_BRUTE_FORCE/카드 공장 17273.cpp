/* 2015112119 ������ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

long long frontCard[200001], backCard[200001];
long long Card[2][200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> frontCard[i] >> backCard[i];
		Card[0][i] = frontCard[i];
	}

	while (m--) {
		cin >> k;
		for (int i = 0; i < n; i++) {
			if (Card[1][i] == 0) {//�ո��ΰ��
				if (Card[0][i] <= k) {//��������Ѵ�.
					Card[1][i] = backCard[i];
					Card[0][i] = 0;
				}
			}
			else {//�޸��ΰ��
				if (Card[1][i] <= k) {//��������Ѵ�.
					Card[0][i] = frontCard[i];
					Card[1][i] = 0;
				}
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < n; i++) answer += Card[0][i] + Card[1][i];
	cout << answer;
}