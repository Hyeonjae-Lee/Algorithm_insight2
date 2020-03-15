
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

vector<int> vec1;

std::map<int, int> mymap;

int main() {
	int a, b, c;

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a;
	
	for (int j = 0; j < a; j++) {
		cin >> c;

		std::map<int, int>::iterator mitfind;
		mitfind = mymap.find(c);
		if (mitfind != mymap.end()) {
			//찾았을 경우
			mymap[c]++;
		}
		else {
			mymap[c] = 1;
		}
	}

	cin >> b;
	for (int j = 0; j < b; j++) {
		cin >> c;

		std::map<int, int>::iterator mitfind;
		mitfind = mymap.find(c);
		if (mitfind == mymap.end()) cout << 0 <<" ";
		else cout << mymap[c]<<" ";
		/*if (binary_search(mymap.begin(), mymap.end(), c)) { cout << mymap[c] << " "; }
		else cout << 0 << " ";*/
	}
}