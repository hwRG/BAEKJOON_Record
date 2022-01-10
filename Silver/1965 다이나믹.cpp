#include <iostream>
using namespace std;

int n, result;
int list[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> list[i];
		dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--){
			if (list[i] > list[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			else if (list[i] == list[j]) 
				if (dp[i] < dp[j])
					dp[i] = dp[j];
		}
	}

	for (int i = 1; i <= n; i++) 
		if (result < dp[i]) result = dp[i];
	cout << result;
}