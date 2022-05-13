#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
bool squr[101][101];


void BFS() {
	int count = 0;
	pair<int, int> cur;
	queue<pair<int, int>> que;
	vector<int> vec;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!squr[i][j]) {
				que.push({ i,j });
				squr[i][j] = true;
				vec.push_back(1);
				count++;
			}
			while (!que.empty()) {
				cur = que.front();
				que.pop();
				for (int i = 0; i < 4; i++) {
					int SY = cur.first + direction[i][0];
					int SX = cur.second + direction[i][1];
					if (SX >= 1 && SX <= N && SY >= 1 && SY <= M && !squr[SY][SX]) {
						que.push({ SY, SX });
						squr[SY][SX] = true;
						vec[count - 1]++;
					}
				}
			}
		}
	}
	cout << count << '\n';
	sort(vec.begin(), vec.end());
	for (int i = 0; i < count; i++)
		cout << vec[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;
	int SX, SY, EX, EY;
	for (int i = 0; i < K; i++) {
		cin >> SX >> SY >> EX >> EY;
		for (int j = SX; j < EX; j++) 
			for (int k = SY; k < EY; k++) 
				squr[k + 1][j + 1] = true;
	}
	BFS();
}