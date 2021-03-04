#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test, max = 0;
	cin >> T;
	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
	for (int i = 0; i < T; i++) {
		cin >> test;
		if (max >= test){
			cout << dp[test] << '\n';
			continue;
		}
		max = test;
		for (int j = 6; j <= test; j++)
			dp[j] = dp[j - 1] + dp[j - 5];
		cout << dp[test] << '\n';
	}
}