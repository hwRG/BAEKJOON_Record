#include <iostream>
using namespace std;

int dp[100001][3];

int main() {
	int N;
	cin >> N;
	
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
	}
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
}


/*
int dp[100001];

int factorial(int num) {
	int total = 0;
	for (int i = num; i > 0; i--)
		total += i;
	return total;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		if (i == 0)	dp[i] = 1;
		else if (i == 1 || i == 2) dp[i] = dp[i-1] + 2 * i;
		else 
			dp[i] = (dp[i - 1] + factorial(i) * (i - 2) + 4) % 9901;
	}
	cout << dp[N];
}
*/