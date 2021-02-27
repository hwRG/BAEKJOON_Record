#include <iostream>
#include <queue>
using namespace std;

int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int T, M, N, K, a, b, farm[50][50];

void BFS() {
	queue<pair<int, int>> que;
	int count = 0;
	for(int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			if(farm[i][j]){
				que.push({ i,j });
				farm[i][j] = 0;
				count++;
			}
			while (!que.empty()) {
				pair<int, int> cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int NY = cur.first + direction[k][0];
					int NX = cur.second + direction[k][1];
					if (NY >= 0 && NY < M && NX >= 0 && NX < N && farm[NY][NX]) {
						que.push({ NY, NX });
						farm[NY][NX] = 0;
					}
				}
			}
		}
	}
	cout << count << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	for(int k = 0; k < T; k++){
		cin >> M >> N >> K; 
		pair<int, int> start;
		bool flag = true;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			farm[a][b] = 1;
		}
		BFS();
	}
}