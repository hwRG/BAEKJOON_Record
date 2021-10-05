#include <iostream>
#include <vector>
using namespace std;

int map[501][501], M, N;
int dp[501][501];

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int  DFS(int y, int x) {
	if (y == M && x == N) 
		return 1;

	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++)
			if (y + dir[i][0] > 0 && y + dir[i][0] <= M && x + dir[i][1] > 0 && x + dir[i][1] <= N)
				if (map[y][x] > map[y + dir[i][0]][x + dir[i][1]])
					dp[y][x] += DFS(y + dir[i][0], x + dir[i][1]);
	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = -1;

	for (int i = 1; i <= M; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> map[i][j];
	cout << DFS(1, 1);
}



/*
#include <iostream>
#include <vector>
using namespace std;

int map[501][501], M, N, cnt = 0;
bool visited[501][501];
vector<int> setting[501][501];

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void DFS(int fir, int sec) {
	if (fir == M && sec == N) {
		cnt++;
		return;
	}
	if (!setting[fir][sec].empty()) {
		for (int i = 0; i < setting[fir][sec].size(); i++) {
			int tempDir = setting[fir][sec][i];
			if (!visited[fir][sec]) {
				visited[fir][sec] = true;
				DFS(fir + dir[tempDir][0], sec + dir[tempDir][1]);
				visited[fir][sec] = false;
			}
		}
	}
	else{
		for (int i = 0; i < 4; i++) {
			if (fir + dir[i][0] > 0 && fir + dir[i][0] <= M && sec + dir[i][1] > 0 && sec + dir[i][1] <= N) {
				if (map[fir][sec] > map[fir + dir[i][0]][sec + dir[i][1]]) {
					setting[fir][sec].push_back(i);
					if(!visited[fir][sec]){
						visited[fir][sec] = true;
						DFS(fir + dir[i][0], sec + dir[i][1]);
						visited[fir][sec] = false;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	DFS(1, 1);
	cout << cnt;
}
*/