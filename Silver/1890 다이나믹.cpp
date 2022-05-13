#include <iostream>
using namespace std;

int boa[101][101];
int N, dir[2][2] = { {1, 0}, {0, 1} };
long long dp[101][101];

long long DFS(int a, int b) {
	if (a == N && b == N)
		return 1;
	else if (boa[a][b] == 0)
		return 0;
	else if (dp[a][b] == 0){
		for (int i = 0; i < 2; i++) {
			int newA = a + dir[i][0] * boa[a][b];
			int newB = b + dir[i][1] * boa[a][b];
			if (newA <= N && newB <= N && newA >= 1 && newB >= 1) 
				dp[a][b] += DFS(newA, newB);
		}
	}
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> boa[i][j];

	DFS(1, 1);
	cout << dp[1][1];
}