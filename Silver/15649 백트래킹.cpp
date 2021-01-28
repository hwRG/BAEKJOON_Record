#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, count = 1;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++){
		count *= M;
		M--;
	}

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= M; j++) {
			cout << i << ' ' << j;
		}
	}
}