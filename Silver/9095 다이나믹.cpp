#include <iostream>
using namespace std;

int main() {
	int T, test, dp[12] = { 0, };
	cin >> T;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int k = 0; k < T; k++){
		cin >> test;
		for (int i = 4; i <= test; i++) 
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		cout << dp[test] << '\n';
	}
}
