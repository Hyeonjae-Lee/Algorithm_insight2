#include <string>
#include <vector>

using namespace std;

long long dp[82];
long long arr[82];

long long solution(int N) {
	long long answer = 0;

	if (N == 1) answer = 4;
	else if (N == 2) answer = 6;
	else {
		dp[1] = 4;
		dp[2] = 6;
		arr[1] = 1;
		arr[2] = 1;
		for (int i = 3; i <= N; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
			dp[i] = dp[i - 1] + arr[i] * 2;
		}
		answer = dp[N];
	}
	return answer;
}

int main() {
	solution(10);
}