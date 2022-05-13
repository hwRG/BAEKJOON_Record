#include <iostream>
using namespace std;

int N, A[1001], dp[1001], sum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> A[i];
		dp[i] = A[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++)
			if (A[i] > A[j]) if (dp[j] + A[i] > dp[i]) dp[i] = dp[j] + A[i];
		if (dp[i] > sum) sum = dp[i];
	}
	cout << sum;
}