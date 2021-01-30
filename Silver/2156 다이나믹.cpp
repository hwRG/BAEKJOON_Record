#include <iostream>
using namespace std;

int dp[10001];
int grape[10001];

int max(int a, int b, int c) {
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else if (c >= a && c >= b)
		return c;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> grape[i];
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++) 
		dp[i] = max(dp[i - 1], grape[i] + dp[i-2], grape[i] + grape[i-1] + dp[i-3]);
	
		cout << dp[n] << '\n';
}