
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;
int arr[500001];

long long int Count = 0;

int n;

void mergefun(int a[], int start, int mid, int end, int size) {
	int	i, startptr, endptr, bufptr;
	
	int *b = new int [size];

	startptr = start; endptr = mid + 1; bufptr = start;

	while (startptr <= mid && endptr <= end) {
		if (a[startptr] < a[endptr]) b[bufptr++] = a[startptr++];
		else {
			Count += (long long int)mid-startptr+1;
			b[bufptr++] = a[endptr++];
		}
	}

	if (startptr > mid) {
		for (i = endptr; i <= end; i++) {
			b[bufptr++] = a[i];
		}
	}
	else {
		for (i = startptr; i <= mid; i++) {
			b[bufptr++] = a[i];
		}
	}

	for (int i = start; i <= end; i++) a[i] = b[i];
	delete[] b;
}

void fun(int a[], int start, int end, int size) {
	int mid = (start + end) / 2;
	if (start < end) {

		fun(a, start, mid, size);
		fun(a, mid + 1, end, size);
		mergefun(a, start, mid, end, size);
		
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	fun(arr, 0, n-1, n);

	cout << Count;
}