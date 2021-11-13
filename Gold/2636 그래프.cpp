#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int n, m, board[101][101], time, cheese;
bool visited[101][101];

bool BFS() {
	queue<pair<int, int>> que;
	que.push({ 1, 1 });
	visited[1][1] = true;

	int count = 0;
	while (!que.empty()) {
		int fir = que.front().first;
		int sec = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int firNext = fir + dir[i][0];
			int secNext = sec + dir[i][1];

			if (!visited[firNext][secNext] && firNext > 0 && secNext > 0 && firNext <= n && secNext <= m){
				if (board[firNext][secNext] == 0){
					que.push({ firNext, secNext });
				}
				else {
					board[firNext][secNext] = 0;
					count++;
				}
			visited[firNext][secNext] = true;
			}
		}
	}

	if (count == 0) {
		time--;
		cout << time << '\n' << cheese;
		return true;
	}
	else {
		cheese = count;
		return false;
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	queue<pair<int, int>> que;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> board[i][j];

	while (1) {
		time++;
		bool flag = BFS();
		if (flag)
			break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				visited[i][j] = false;
	}
}

/*
pair<int, int> find_zero() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			if (board[i][j] == 0 && !visited[i][j]) 
				return { i,j };

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	queue<pair<int, int>> que;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				que.push({ i,j });
		}
	}
	BFS(1, 1);
	int time = 0;
	queue< pair<int, int>> tempQue;
	int nextCount = 0, beforeCount = que.size(), cnt = 0;

	while (!que.empty()) {
		if (cnt == beforeCount) {
			while (!tempQue.empty()) {
				board[tempQue.front().first][tempQue.front().second] = 0;
				visited[tempQue.front().first][tempQue.front().second] = true;
				tempQue.pop();
			}
			pair<int, int> zero = find_zero();
			BFS(zero.first, zero.second);

			beforeCount = nextCount;
			nextCount = 0;
			cnt = 0;
			time++;
		}

		bool flag = true;
		int fir = que.front().first;
		int sec = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int firNear = fir + dir[i][0];
			int secNear = sec + dir[i][1];

			if (firNear > 0 && secNear > 0 && firNear <= n && secNear <= m) {
				if (visited[firNear][secNear] && board[firNear][secNear] == 0) {
					flag = false;
					break;
				}
			}
		}
		if (!flag)
			tempQue.push({ fir,sec });
		else{
			nextCount++;
			que.push({ fir,sec });
		}
		cnt++;
	}
	time++;
	cout << time << '\n' << beforeCount;

}*/