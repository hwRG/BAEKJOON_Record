#include <iostream>
using namespace std;

long long dp[91];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, count = 2;
	cin >> N;
	dp[1] = 1; dp[2] = 1; dp[3] = 2;
	for (int i = 4; i <= N; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N];
}