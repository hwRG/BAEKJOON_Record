#include <iostream>
using namespace std;

int dp[41][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	cin >> N;
	dp[0][0] = dp[1][1] = 1;
	dp[0][1] = dp[1][0] = 0;
	for (int k = 0; k < N; k++) {
		cin >> num;
		if(dp[num][0] != 0 && num != 0 && num != 1){
			dp[num][0] = dp[num - 1][0] + dp[num - 2][0];
			dp[num][1] = dp[num - 1][1] + dp[num - 2][1];
		}
		else if(num != 0 && num != 1){
			int start = 2;
			while (dp[start][0] != 0) 
				start++;
			for(int i = start; i <= num; i++){
				dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
				dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
			}
		}
		cout << dp[num][0] << ' ' << dp[num][1] << '\n';
	}
}