#include <iostream>
#include <string>
using namespace std;

int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int R, C, MAX;
bool alphabet[26], visited[21][21];
char alp[21][21];

void DFS(int y, int x, int count){
	bool flag = false;
	MAX = (MAX > count) ? MAX : count;
	for (int i = 0; i < 4; i++) {
		int NY = y + direction[i][0];
		int NX = x + direction[i][1];
		if (NY >= 1 && NY <= R && NX >= 1 && NX <= C && !alphabet[alp[NY][NX] - 65] && !visited[NY][NX]) {
			alphabet[alp[NY][NX] - 65] = true;
			visited[NY][NX] = true;
			flag = true;
			DFS(NY, NX, count+1);
			visited[NY][NX] = false;
			alphabet[alp[NY][NX] - 65] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= C; j++) 
			alp[i][j] = str[j-1];
	}
	alphabet[alp[1][1] - 65] = true;
	DFS(1, 1, 1);
	cout << MAX;
}