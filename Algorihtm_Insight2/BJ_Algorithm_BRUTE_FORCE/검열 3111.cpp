/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
const int MOD = 1000000000;
// 부호 상관없는 정수 n이 주어지면 모듈라 정수계 속의 값을 리턴
inline int mod(long long n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1) * MOD + n) % MOD; // 음수일 경우
}

void rabinkarf(string arr, string srr) {//arr는 패턴 srr는 단어 총량

	int srr_length = srr.size();
	int arr_length = arr.size();

	bool same_first = false;
	bool same_end = false;
	for (int i = 0; srr_length - arr_length; i++) {
		same_first = false;
		for (int j = i; j < i + arr_length; j++) {
			if (arr[j] != srr[i + j]) {
				same_first = true;
				break;
			}
		}

		if (!same_first) {
			srr.erase(i, i + arr_length);
			break;
		}
	}

}

int main() {
	string A, T;

	cin >> A >> T;

	rabinkarf(A, T);
}