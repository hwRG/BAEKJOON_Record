#include <iostream>
#include <algorithm>
using namespace std;

int dp[301], arr[301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, score, cur = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1] = arr[1], dp[2] = arr[1] + arr[2], dp[3] = max(arr[2] + arr[3], arr[1] + arr[3]);
	for (int i = 4; i <= N; i++)
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	cout << dp[N];
}