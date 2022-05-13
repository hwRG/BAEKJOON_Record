#include <iostream>
#include <algorithm>
using namespace std;

int W[10002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, min = 1000000000;
	cin >> n;
	int cnt = n * 2;
	
	for (int i = 1; i <= cnt; i++)
		cin >> W[i];
	sort(W + 1, W + cnt + 1);

	for (int i = 1; i <= n; i++){
		(min > W[i] + W[cnt - i + 1]) ? min = W[i] + W[cnt - i + 1] : min = min;
	}
	cout << min;
}