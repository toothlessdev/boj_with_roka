#include<iostream>
#include<algorithm>
using namespace std;

int len;
int triangle[500][500], dp[500][500];

int main() {
	cin >> len;

	for (int y = 0; y < len; y++) {
		for (int x = 0; x <= y; x++) {
			cin >> triangle[y][x];
		}
	}

	// init
	dp[0][0] = triangle[0][0];
	dp[1][0] = triangle[0][0] + triangle[1][0];
	dp[1][1] = triangle[0][0] + triangle[1][1];

	for (int y = 1; y < len; y++) {
		for (int x = 0; x <= y; x++) {
			if (x == 0) {
				dp[y][x] = dp[y - 1][x] + triangle[y][x];
			}
			else {
				dp[y][x] = max(dp[y - 1][x - 1] + triangle[y][x], dp[y - 1][x] + triangle[y][x]);
			}
		}
	}


	int maxSum = 0;
	for (int x = 0; x < len; x++) {
		maxSum = maxSum < dp[len-1][x] ? dp[len-1][x] : maxSum;
	}
	cout << maxSum << '\n';

	return 0;
}