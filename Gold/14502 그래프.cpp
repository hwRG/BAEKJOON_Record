#include <iostream>
#include <queue>
using namespace std;

int matrix[8][8];
int visited[8][8];
int N, M, result;
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

void BFS() {
	queue<pair<int, int>> que;
	int temp[8][8], surv = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = matrix[i][j];
			if (temp[i][j] == 2) 
				que.push(make_pair(i, j));
		}
	}

	while (!que.empty()) {
		pair<int, int> current = que.front();
		int TX, TY;
		que.pop();
		for (int i = 0; i < 4; i++) {
			TX = current.first + direction[i][0];
			TY = current.second + direction[i][1];
			if (TX >= 0 && TX < N && TY >= 0 && TY < M && temp[TX][TY] == 0) {
				temp[TX][TY] = 2;
				que.push(make_pair(TX,TY));
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				surv++;
	if (result < surv) result = surv;
}

void DFS(int count, int x, int y) {
	if (count == 3) {
		BFS();
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = 1;
				DFS(count + 1, i, j);
				matrix[i][j] = 0;
			}
		}
		y = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> matrix[i][j];
	DFS(0, 0, 0);

	cout << result;
}