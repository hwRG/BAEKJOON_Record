#include <iostream>
#include <algorithm>
using namespace std;

int list[1001], dp[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, MAX = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> list[i];
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) 
			if (list[i] > list[j]) 
				dp[i] = max(dp[i], dp[j] + 1);
		MAX = max(MAX, dp[i]);
	}
	cout << MAX;
}