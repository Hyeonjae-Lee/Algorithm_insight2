
/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

int Count = 999999;
pair<int, int> maxc = { 0,0 };
vector<pair<int, int>> a;

bool check(pair<int, int>ta, pair<int, int>tb) {
	return ta.first + ta.second < tb.first + tb.second;
}

//거리 구하기
int check2(pair<int, int>ta, pair<int, int>tb) {
	return pow(ta.first - tb.first, 2) + pow(ta.second - tb.second, 2);
}

void mergefun(int start, int mid, int end, int size) {
	int	i, startptr, endptr, bufptr;
	vector<pair<int, int>> b;
	b.resize(size);

	startptr = start; endptr = mid + 1; bufptr = start;

	while (startptr <= mid && endptr <= end) {
		int temp = check2(a[startptr], a[endptr]);
		Count = min(Count, temp);
		if (check(a[startptr], a[endptr])) {
			b[bufptr++] = a[startptr++];
		}
		else {			
			b[bufptr++] = a[endptr++];
		}

	}

	if (startptr > mid) {
		for (i = endptr; i <= end; i++) {
			b[bufptr++] = a[i];

			int temp = check2(a[startptr], a[i]);
			Count = min(Count, temp);
		}
	}
	else {
		for (i = startptr; i <= mid; i++) {

			b[bufptr++] = a[i];

			int temp = check2(a[endptr], a[i]);
			Count = min(Count, temp);
		}
	}

	for (int i = start; i <= end; i++) a[i] = b[i];
}

void fun(int start, int end, int size) {
	if (start < end) {
		fun(start, (start + end) / 2, size);
		fun((start + end) / 2 + 1, end, size);
		mergefun(start, (start + end) / 2, end, size);
	}
}

bool desc(pair<int, int>ta, pair<int, int>tb) {
	Count = min(Count, check2(ta, tb));
	if (ta.first != tb.first) return ta.first > tb.second;
	else return ta.second > tb.second;
}

int main() {
	int n;

	cin >> n;

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	//fun(0, n-1, n);

	sort(a.begin(), a.end(), desc);


	cout << Count;
}