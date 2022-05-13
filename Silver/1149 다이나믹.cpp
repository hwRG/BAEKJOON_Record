#include <iostream>
#include <algorithm>
using namespace std;

int list[1001][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> list[i][0] >> list[i][1] >> list[i][2];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) 
				list[i][0] = list[i][0] + min(list[i - 1][1], list[i - 1][2]);
			else if (j == 1) 
				list[i][1] = list[i][1] + min(list[i - 1][0], list[i - 1][2]);
			else if (j == 2) 
				list[i][2] = list[i][2] + min(list[i - 1][0], list[i - 1][1]);
		}
	}
	int ans = list[N][0];
	for (int i = 1; i < 3; i++) 
		if (ans > list[N][i]) ans = list[N][i];
	cout << ans;
}