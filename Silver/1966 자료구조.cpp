#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int TC, N, M, value, check;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		queue<pair<int, int>> que;
		priority_queue<int> pque;

		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> value;
			pair<int, int> temp = { value, j };

			que.push(temp);
			pque.push(value);
		}

		int cnt = 0;
		while (!que.empty()) {
			int val = que.front().first;
			int ind = que.front().second;
			que.pop();
			if (pque.top() == val) {
				cnt++;
				if (M == ind) {
					cout << cnt << '\n';
					break;
				}
				pque.pop();
			}
			else
				que.push({ val, ind });
		}
	}
}


// Priority Queue ±¸Çö
/*

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int TC, N, M, index, check;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> N >> M;
		queue<pair<int,int>> que;

		for (int j = 0; j < N; j++) {
			cin >> index;
			pair<int,int> temp = { index, j };
			bool flag = false;
			if (que.empty()){
				que.push(temp);
				continue;
			}
			for (int i = 0; i < que.size(); i++) {
				if (que.front().first < index) {
					que.push(temp);
					for (int j = i; j < que.size() - 1; j++) {
						que.push(que.front());
						que.pop();
					}
					flag = true;
					break;
				}
				else {
					que.push(que.front());
					que.pop();
				}
			}
			if (!flag)
				que.push(temp);

		}
		int cnt = 1;
		while (!que.empty()) {
			if (M == que.front().second) {
				cout << cnt << '\n';
				break;
			}
			que.pop();
			cnt++;
		}
	}
}*/