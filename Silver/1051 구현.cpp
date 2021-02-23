#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, MAX, result;
	int quad[51][51];
	string str;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) 
			quad[i][j] = str[j-1]-48;
	}
	(N > M) ? MAX = M : MAX = N;
	for (int k = MAX; k >= 1; k--) {
		for (int i = 1; i <= N - k + 1; i++) {
			for (int j = 1; j <= M - k + 1; j++) {
				if (quad[i][j] == quad[i + k - 1][j] && quad[i][j] == quad[i][j + k - 1] && quad[i][j] == quad[i + k - 1][j + k - 1]){
					cout << k * k;
					return 0;
				}
			}
		}
	}
}