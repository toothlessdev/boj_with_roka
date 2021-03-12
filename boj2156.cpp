#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, wine[10000], dp[10000];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	for (int i = 2; i < n; i++) {
		vector<int> arr = { dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] };
		sort(arr.begin(), arr.end());
		dp[i] = arr.back();
	}

	cout << dp[n - 1] << '\n';

	return 0;
}