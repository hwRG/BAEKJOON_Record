#include <iostream>
using namespace std;

long long dp[1000001], n, T, top = 4;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for (int j = top; j <= n; j++) 
			dp[j] = (dp[j - 3] + dp[j - 2] + dp[j - 1]) % 1000000009;

		cout << dp[n] % 1000000009 << '\n';

		if (top < n) top = n;
	}
	return 0;
}