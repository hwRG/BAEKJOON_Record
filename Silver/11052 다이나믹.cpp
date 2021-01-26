#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int p[10001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (dp[i] < dp[i - j] + p[j]) dp[i] = dp[i - j] + p[j];
	cout << dp[N];
}