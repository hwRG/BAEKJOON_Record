#include <iostream>
using namespace std;

int dp[100001][2];
int res[100001][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, n, max, DB;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> dp[i][0];
		for (int i = 1; i <= n; i++) cin >> dp[i][1];
		res[1][0] = dp[1][0], res[1][1] = dp[1][1];
		res[2][0] = dp[2][0] + dp[1][1], res[2][1] = dp[2][1] + dp[1][0];
		for (int i = 3; i <= n; i++) {
			DB = (res[i - 2][0] > res[i - 2][1]) ? res[i - 2][0] : res[i - 2][1];
			res[i][0] = (dp[i][0] + res[i - 1][1] > DB + dp[i][0]) ? dp[i][0] + res[i - 1][1] : DB + dp[i][0];
			res[i][1] = (dp[i][1] + res[i - 1][0] > DB + dp[i][1]) ? dp[i][1] + res[i - 1][0] : DB + dp[i][1];
		}
		max = (res[n][0] > res[n][1]) ? res[n][0] : res[n][1] ;
		cout << max << '\n';
	}
}