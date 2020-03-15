#include <iostream>
#include <vector>

using namespace std;

long long int dp[32];

int main() {
	int n; dp[1] = 1;
	
	for (int i = 2; i <= 30; i++) dp[i] = dp[i - 1] * (2 * i) * (2 * i - 1) / (i * (i + 1));
	
	while (scanf_s("%d", &n) == 1) {
		if (n == 0) break;
		cout << dp[n]<<'\n';
	}
}