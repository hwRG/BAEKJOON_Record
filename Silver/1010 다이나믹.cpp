#include <iostream>
using namespace std;
// Combination으로 해결하려 했으나, 숫자가 너무 커짐
int dp[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, M;
	cin >> T;

	for (int i = 1; i <= 30; i++){
			dp[1][i] = i;
			dp[i][i] = 1;
	}
	for (int k = 0; k < T; k++) {
		cin >> N >> M;
		for (int i = 2; i <= N; i++) 
			for (int j = 2; j <= M; j++) 
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		cout << dp[N][M] << '\n';
	}
}