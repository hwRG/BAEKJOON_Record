#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LCS[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string first, second;
	cin >> first >> second;
	for (int i = 1; i <= first.length(); i++) 
		for (int j = 1; j <= second.length(); j++) 
			LCS[i][j] = max({ LCS[i - 1][j], LCS[i][j - 1], LCS[i - 1][j - 1] + (first[i-1] == second[j-1]) });
	cout << LCS[first.length()][second.length()];
}
// 다중 비교는 중괄호{}를 사용