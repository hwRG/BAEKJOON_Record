#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[2][1001];
string str[2][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string first, second;
	cin >> first >> second;
	for (int i = 1; i <= first.length(); i++) {
		for (int j = 1; j <= second.length(); j++) {
			dp[i % 2][j] = max({ dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1] + (first[i - 1] == second[j - 1]) });
			if (dp[i % 2][j] == dp[(i - 1) % 2][j]) str[i % 2][j] = str[((i - 1) % 2)][j];
			else if (dp[i % 2][j] == dp[i % 2][j - 1]) str[i % 2][j] = str[i % 2][j - 1];
			else if (dp[i % 2][j] == dp[(i - 1) % 2][j - 1] + (first[i - 1] == second[j - 1])) 
				str[i % 2][j] = str[(i - 1) % 2][j - 1] + first[i - 1];
		}
	}
	cout << dp[first.length() % 2][second.length()] << '\n';
	cout << str[first.length() % 2][second.length()];
}