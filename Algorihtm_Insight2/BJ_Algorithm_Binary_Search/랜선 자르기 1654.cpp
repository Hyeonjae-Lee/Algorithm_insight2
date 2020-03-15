
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

int Wires[10005];

int main() {
	long long int N, Need_Number;
	long long int finalans=0;

	std::cin >> N >> Need_Number;
	
	for (int i = 0; i < N; i++) {	
		std::cin >> Wires[i];
	}

	long long int Left = 1, Right = 2147483647, Mid, Sum;
	
	while (Left <= Right) {
		Sum = 0;
		Mid = (Right + Left) / 2;

		for (int i = 0; i < N; i++) {
			Sum += (Wires[i] / Mid);
		}
		if (Sum < Need_Number) {
			Right = Mid - 1;
		}
		else {
			Left = Mid + 1;
			finalans = Mid;
		}
	}

	std::cout << finalans;
	return 0;
}