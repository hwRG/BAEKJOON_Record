#include <iostream>
#include <queue>
using namespace std;

int A, B;

void BFS(int A) {
	queue<pair<int, int>> que;
	if(A == B){
		cout << 1;
		return;
	}
	que.push({ A, 1 });

	while (!que.empty()) {
		pair<int, int> temp = que.front();
		que.pop();
		if (temp.first == B) {
			cout << temp.second;
			return;
		}
		if (temp.first * 2 <= B)
			que.push({ temp.first * 2, temp.second + 1 });
		if (temp.first * 10 + 1 <= B && temp.first <= 100000000)
			que.push({ temp.first * 10 + 1, temp.second + 1 });
	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> A >> B;
	BFS(A);
}


/*
int DFS(int now) {
	cnt++;
	if (B == now) {
		flag = true;
		return cnt;
	}
	if (B < now) {
		return -1;
	}
	if (cnt == DFS(now * 2) && flag)
		return cnt;
	cnt--;
	if (cnt == DFS(now * 10 + 1) && flag)
		return cnt;
	cnt--;

	return -1;

}*/