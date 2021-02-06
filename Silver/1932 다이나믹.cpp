#include <iostream>
#include <algorithm>
using namespace std;

int tra[501][501];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, big = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> tra[i][j];
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			tra[i][j] += max(tra[i - 1][j - 1], tra[i - 1][j]);
	for (int i = 1; i <= n; i++) 
		if (big < tra[n][i]) big = tra[n][i];
	cout << big;
}