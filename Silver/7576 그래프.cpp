#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cur;
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int box[1001][1001];
vector<pair<int, int>> start;

void BFS() {
	int count = 0;
	queue<pair<int, int>> que;
	for (int i = 0; i < start.size(); i++) {
		que.push(start[i]);
		box[start[i].first][start[i].second] = 2;
	}
	while (1) {
		queue<pair<int, int>> temp;
		bool flag = false;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int NY = cur.first + direction[i][0];
				int NX = cur.second + direction[i][1];
				if (box[NY][NX] == 0 && NY >= 1 && NY <= N && NX >= 1 && NX <= M) {
					temp.push({ NY, NX });
					box[NY][NX] = 2;
					flag = true;
				}
			}
		}
		if (!flag) break;
		que = temp;
		count++;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0){
				cout << -1;
				return;
			}
		}
	}
	cout << count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> cur;
			box[i][j] = cur;
			if (cur == 1) start.push_back({ i,j });
		}
	}
	BFS();
}