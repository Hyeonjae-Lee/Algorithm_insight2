/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int heap[100001];
int hn;

int pop() {
	int ans = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0;

	for (int i = 1; i * 2 <= hn;) {
		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) break;
		else if (heap[i * 2] > heap[i * 2 + 1]) {
			swap(heap[i], heap[i * 2]);
			i = i * 2;
		}
		else {
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return ans;
}

void push(int x) {
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) {
			swap(heap[i / 2], heap[i]);
		}
		else break;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int testcase, x;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> x;

		if (x == 0) {

			if (heap[1] == 0) cout << 0 << '\n';
			else {
				cout << pop() << '\n';
			}

		}
		else {
			push(x);
		}
	}

}