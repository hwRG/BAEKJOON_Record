#include <iostream>
using namespace std;

int T, N, M;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		int fir, sec;
		for (int i = 0; i < M; i++) 
			cin >> fir >> sec;
		cout << N - 1 << '\n';
	}

}