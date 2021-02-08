#include <iostream>
using namespace std;

int list[100000];
int dp[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		dp[i] = list[i];
	}
	int max = list[0];
	for (int i = 1; i < n; i++) {
		if (dp[i] < dp[i-1] + list[i]) dp[i] = dp[i - 1] + list[i];
		if (dp[i] > max) max = dp[i];
	}
	cout << max;
}