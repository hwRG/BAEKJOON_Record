#include <iostream>
#include <algorithm>
using namespace std;

int dp[16], list[16][2], N, MAX;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> list[i][0] >> list[i][1];
	for (int i = N; i >= 1; i--) {
		if (i + list[i][0] - 1 > N) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + list[i][0]] + list[i][1], dp[i + 1]);
	}
	for (int i = 1; i <= N; i++) 
		if (MAX < dp[i]) MAX = dp[i];
	cout << MAX;
}