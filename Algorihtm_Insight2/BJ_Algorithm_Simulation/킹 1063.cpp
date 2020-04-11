#include <iostream>
#include <algorithm>

using namespace std;
string srr1, srr2, srr;
int n;
pair <int, int> kpos, spos;

string order[] = { "R","L","B","T","RT","LT","RB","LB" };

int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };

bool check(int a, int b) {
	return (a <= 8 && b <= 8 && a >= 1 && b >= 1);
}

void func(string srr) {
	for (int i = 0; i < 8;i++) {
		if (order[i] == srr) {
			pair <int, int> temppos = { kpos.first + dx[i], kpos.second + dy[i] };

			if (!check(temppos.first, temppos.second)) return;
			else if ( spos == kpos ){
				pair <int, int> temppos2 = { spos.first + dx[i], spos.second + dy[i] };
				if (!check(temppos2.first, temppos2.second)) return;
				spos = temppos2;
			}

			kpos = temppos;
		}
	}
}

int main() {

	cin >> srr1 >> srr2 >> n;
	kpos.first = srr1[0] - 'A' + 1;
	kpos.second = srr1[1] - '0';
	spos.first = srr2[0] - 'A' + 1;
	spos.second = srr2[1] - '0';

	while (n--) {
		cin >> srr;
		func(srr);
	}

	cout << (char)(kpos.first + 'A' - 1) << kpos.second << '\n';
	cout << (char)(spos.first + 'A' - 1) << spos.second << '\n';
}

