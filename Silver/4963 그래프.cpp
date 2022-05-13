#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int direction[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
int map[50][50];
int w, h;

void BFS() {
	queue<pair<int, int>> que;
	bool visited[50][50] = { 0, };
	int count = 0, SX, SY;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				que.push(make_pair(i, j));
				visited[i][j] = true;
				count++;
			}
			while (!que.empty()){
				pair<int, int> now = que.front();
				que.pop();
				for (int k = 0; k < 8; k++) {
					SY = now.first + direction[k][0];
					SX = now.second + direction[k][1];
					if (SY >= 0 && SY < h && SX >= 0 && SX < w && map[SY][SX] && !visited[SY][SX]) {
						que.push(make_pair(SY, SX));
						visited[SY][SX] = true;
					}
				}
			}
		}
	}
	cout << count << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) 
				cin >> map[i][j];
		BFS();
	}
}