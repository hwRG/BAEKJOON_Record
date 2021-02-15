#include <iostream>
#include <queue>
using namespace std;

int direction[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
int map[101][101], go[101], L, N, K;
char dir[101];

void snake() {
	queue<pair<int, int>> que, tempQ;
	int cur = 0, SX = 1, SY = 1, count = 0, conv = 0;
	bool flag = true;
	que.push(make_pair(1, 1));
	while (1) {
		cur %= 4;
		if (cur == -1) cur = 3;
		SX += direction[cur][0];
		SY += direction[cur][1];
		que.push(make_pair(SX, SY));
		tempQ = que;
		if (que.size() > 1) {
			while (tempQ.size() > 1) {
				pair<int, int> temp = tempQ.front();
				tempQ.pop();
				if (temp == make_pair(SX, SY)) {
					flag = false;
					break;
				}
			}
			if (flag == false) break;
		}
		if (SX < 1 || SX > N || SY < 1 || SY > N) break;
		if (map[SY][SX] == 0) 
			que.pop();
		if (map[SY][SX] == 1) 
			map[SY][SX] = 0;
		count++;
		if (count == go[conv]) {
			if (dir[conv] == 'D') cur++;
			else if (dir[conv] == 'L') cur--;
			conv++;
		}
	}
	cout << count + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> go[i] >> dir[i];
	snake();
}