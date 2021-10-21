#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int plate[5][5];
set<string> store;
/*
bool check(string str) {
	for (int i = 0; i < store.size(); i++)
		if (store[i] == str)
			return true;
	return false;
}
*/
void DFS(int a, int b, string str) {
	if (str.size() == 6) {
		store.insert(str);
		return;
	}
	else{
		for (int i = 0; i < 4; i++){
			if(a + dir[i][0] >= 0 && a + dir[i][0] < 5 && b + dir[i][1] >= 0 && b + dir[i][1] < 5 && str.size() < 6)
				DFS(a + dir[i][0], b + dir[i][1], str + char(plate[a][b]));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> plate[i][j];

	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			DFS(i, j, "");
	cout << store.size();
}