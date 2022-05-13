#include <iostream>
#include <cmath>
using namespace std;

int dp[100001], N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) dp[i] = i;
	for (int i = 2; i <= N; i++) 
		for (int j = 2; j * j <= i; j++) dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[N];
}