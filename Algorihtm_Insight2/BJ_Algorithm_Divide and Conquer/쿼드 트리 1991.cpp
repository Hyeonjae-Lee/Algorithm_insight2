
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

int n;
int arr[65][65];

void fun(int start, int end, int divide) {

	bool flag = true;
	for (int i = start; i < divide + start; i++){
		for (int j = end; j < end + divide; j++) {
			if (arr[i][j] != arr[start][end]){
				flag = false;
				break;
			}
		}
	}

	if (!flag) {//다 같은 색이 아닌경우
		cout << "(";
		fun(start, end, divide / 2);
		fun(start, end + divide / 2, divide / 2);
		fun(start + divide / 2, end, divide / 2);
		fun(start + divide / 2, end + divide / 2, divide / 2);
		cout << ")";
	}
	else {
		cout << arr[start][end];
	}


}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) scanf_s("%1d", &arr[i][j]);
	

	fun(0, 0, n);
}