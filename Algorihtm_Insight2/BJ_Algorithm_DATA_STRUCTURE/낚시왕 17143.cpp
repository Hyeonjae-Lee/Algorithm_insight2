#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int check[101][101];
int check2[101][101];

class Shark {
public:
	int r, c, speed, direction, size;
	Shark(int a, int b, int c, int d, int e) : r(a), c(b), speed(c), direction(d), size(e) {}
};

bool desc(Shark a, Shark b) {
	return a.size < b.size;
}

int main() {
	int r, c, m, a, b, C, d, e;
	int ans = 0;
	cin >> r >> c >> m;

	vector<Shark> vec;

	while (m--) {
		cin >> a >> b >> C >> d >> e;//�Է�
		vec.push_back(Shark(a, b, C, d, e));
	}

	sort(vec.begin(), vec.end(), desc);

	for (int i = 1; i <= c; i++) {
		//���� i���� �ִ� ��� �� ���� ������ �ִ� �� óġ

		vector<Shark> tempvec;
		int min = 99999;
		int size = 0;
		int checkflag = 0;
		bool flag = false;

		for (int j = 0; j < vec.size(); j++) {//��� ���� ��
			if (vec[j].c == i) {//���� �ִ� ���� �մ°��
				if (min > vec[j].r) {//���� ������ �ִ� �༮�� ã�´�
					min = vec[j].r; flag = true;
					size = vec[j].size;
					checkflag = j;
				}
			}
		}

		if (flag) {
			vec.erase(vec.begin() + checkflag);//��� ����
			ans += size;
		}

		memset(check, 0, sizeof(check));

		//���� �� �̵���Ų��.
		for (int j = 0; j < vec.size(); j++) {
			
			if (vec[j].direction == 1 || vec[j].direction == 2) {//������ ���Ʒ��ΰ��
				int tempspeed = (vec[j].speed) % ((r - 1) * 2);

				for (int k = 0; k < tempspeed; k++) {
					if ((vec[j].r == 1 && vec[j].direction == 1) || (vec[j].r == r && vec[j].direction == 2)) {
						if (vec[j].direction == 1) vec[j].direction = 2;
						else vec[j].direction = 1;
					}

					//��� �̵�
					if (vec[j].direction == 1)vec[j].r--;
					else vec[j].r++;
				}
			}
			else {//������ �¿��� ���
				int tempspeed = (vec[j].speed) % ((c - 1) * 2);

				for (int k = 0; k < tempspeed; k++) {

					if ((vec[j].c == 1 && vec[j].direction == 4) || (vec[j].c == c && vec[j].direction == 3)) {
						//���� ��� ���� ü����
						if (vec[j].direction == 3) vec[j].direction = 4;
						else vec[j].direction = 3;
					}

					//��� �̵�
					if (vec[j].direction == 3)vec[j].c++;
					else vec[j].c--;
				}
			}

			//�� �̵��ϰ� ��Ƹ����� ��� ���
			if (!check[vec[j].r][vec[j].c]) {
				//ó���� �� �������
				check[vec[j].r][vec[j].c] = 1;
				tempvec.push_back(vec[j]);
			}
			else {
				for (int k = 0; k < tempvec.size(); k++) {
					if (tempvec[k].r == vec[j].r && tempvec[k].c == vec[j].c) {//��ġ�� ���� ���

						if (tempvec[k].size < vec[j].size) tempvec[k] = vec[j];
						break;
					}
				}
			}
		}

		vec = tempvec;
	}

	cout << ans;
}