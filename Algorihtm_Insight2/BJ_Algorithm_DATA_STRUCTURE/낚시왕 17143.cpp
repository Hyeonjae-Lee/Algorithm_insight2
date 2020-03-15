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
		cin >> a >> b >> C >> d >> e;//입력
		vec.push_back(Shark(a, b, C, d, e));
	}

	sort(vec.begin(), vec.end(), desc);

	for (int i = 1; i <= c; i++) {
		//먼저 i열에 있는 상어 중 가장 가까이 있는 상어를 처치

		vector<Shark> tempvec;
		int min = 99999;
		int size = 0;
		int checkflag = 0;
		bool flag = false;

		for (int j = 0; j < vec.size(); j++) {//상어 모음 중
			if (vec[j].c == i) {//지금 있는 열에 잇는경우
				if (min > vec[j].r) {//가장 가까이 있는 녀석을 찾는다
					min = vec[j].r; flag = true;
					size = vec[j].size;
					checkflag = j;
				}
			}
		}

		if (flag) {
			vec.erase(vec.begin() + checkflag);//상어 제거
			ans += size;
		}

		memset(check, 0, sizeof(check));

		//이제 상어를 이동시킨다.
		for (int j = 0; j < vec.size(); j++) {
			
			if (vec[j].direction == 1 || vec[j].direction == 2) {//방향이 위아래인경우
				int tempspeed = (vec[j].speed) % ((r - 1) * 2);

				for (int k = 0; k < tempspeed; k++) {
					if ((vec[j].r == 1 && vec[j].direction == 1) || (vec[j].r == r && vec[j].direction == 2)) {
						if (vec[j].direction == 1) vec[j].direction = 2;
						else vec[j].direction = 1;
					}

					//상어 이동
					if (vec[j].direction == 1)vec[j].r--;
					else vec[j].r++;
				}
			}
			else {//방향이 좌우인 경우
				int tempspeed = (vec[j].speed) % ((c - 1) * 2);

				for (int k = 0; k < tempspeed; k++) {

					if ((vec[j].c == 1 && vec[j].direction == 4) || (vec[j].c == c && vec[j].direction == 3)) {
						//닿은 경우 방향 체인지
						if (vec[j].direction == 3) vec[j].direction = 4;
						else vec[j].direction = 3;
					}

					//상어 이동
					if (vec[j].direction == 3)vec[j].c++;
					else vec[j].c--;
				}
			}

			//상어가 이동하고 잡아먹히는 상어 계산
			if (!check[vec[j].r][vec[j].c]) {
				//처음에 상어가 없을경우
				check[vec[j].r][vec[j].c] = 1;
				tempvec.push_back(vec[j]);
			}
			else {
				for (int k = 0; k < tempvec.size(); k++) {
					if (tempvec[k].r == vec[j].r && tempvec[k].c == vec[j].c) {//위치가 같은 경우

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