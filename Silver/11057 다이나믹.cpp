#include <iostream>
using namespace std;

int dp[1001][10], result, N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 9; j >= 0; j--){ 
			for (int k = j; k >= 0; k--) dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	}
	for (int i = 0; i < 10; i++) {
		result += dp[N][i];
		result %= 10007;
	}
	cout << result;
}