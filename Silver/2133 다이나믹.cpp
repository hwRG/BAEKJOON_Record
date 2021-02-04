#include <iostream>
using namespace std;

int dp[31];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	if (N % 2) {
		cout << 0;
		return 0;
	}
	dp[0] = 1, dp[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 0; j < i - 2; j += 2)
			dp[i] += dp[j] * 2;
	}
	cout << dp[N];
}