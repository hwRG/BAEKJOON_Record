#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int matrix[102][102];

void BFS(int i, int j) {
	queue<pair<int, int>> que;
	int X, Y;
	pair <int, int> current;
	que.push(make_pair(i,j));
	while (!que.empty()) {
		current = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			X = current.first + direction[i][0];
			Y = current.second + direction[i][1];
			if (X >= 1 && Y >= 1 && X <= N && Y <= M && matrix[X][Y] == 1) {
				que.push(make_pair(X, Y));
				matrix[X][Y] = matrix[current.first][current.second] + 1;
			}
		}
	}
	cout << matrix[N][M];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string temp;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 1; j <= temp.length(); j++) 
			matrix[i][j] = int(temp[j-1]) - 48;
	}
	BFS(1, 1);
}