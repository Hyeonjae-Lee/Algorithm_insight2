
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

vector<int> invec;
vector<int> postvec;
vector<int> position;

int n;

void fun(int is, int ie,int ps,int pe) {

	if (ie < is || pe < ps) return;

	cout << postvec[pe] << " ";
	
	int i = position[postvec[pe]];

	fun(is, i - 1, ps, ps + i - is - 1);
	fun(i + 1, ie, ps+ i-is, pe - 1);
}

int main() {
	
	cin >> n;
	
	invec.resize(n+1);
	postvec.resize(n+1);
	position.resize(n+1);

	for (int i = 0; i < n; i++) cin >> invec[i];
	for (int i = 0; i < n; i++) cin >> postvec[i];
	for (int i = 0; i < n; i++) position[invec[i]] = i;

	fun(0, n - 1, 0, n - 1);
}