#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

struct Thing {
	int W, V;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Thing T[101];
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> T[i].W >> T[i].V;

	for (int i = 1; i <= N; i++)
		for (int j = K; j >= 1; j--)
			if (T[i].W <= j)
				dp[j] = max(dp[j], dp[j - T[i].W] + T[i].V);
	cout << dp[K];
}