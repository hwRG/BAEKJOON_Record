#include <iostream>
#include <queue>
using namespace std;

int N, land[101][101], direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
bool visited[101][101];
queue<pair<int, int>> que;
pair<int, int> cur;

int BFS(int min){
	int count = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (land[i][j] <= min) {
				que.push({ i,j });
				visited[i][j] = true;
			}
			while (!que.empty()) {
				cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int NY = cur.first + direction[k][0];
					int NX = cur.second + direction[k][1];
					if (NY >= 1 && NY <= N && NX >= 1 && NX <= N && !visited[NY][NX] && land[NY][NX] <= min) {
						que.push({ NY,NX });
						visited[NY][NX] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				que.push({ i, j });
				count++;
			}
			while (!que.empty()) {
				cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int NY = cur.first + direction[k][0];
					int NX = cur.second + direction[k][1];
					if (NY >= 1 && NY <= N && NX >= 1 && NX <= N && !visited[NY][NX]) {
						que.push({ NY,NX });
						visited[NY][NX] = true;
					}
				}
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int result, remain = 1, MAX = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> land[i][j];
			if (land[i][j] > MAX)
				MAX = land[i][j];
		}
	}
	for(int i = 1; i <= MAX; i++){
		result = BFS(i);
		if(result > remain) remain = result;
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) visited[i][j] = false;
	}
	
	cout << remain;
}