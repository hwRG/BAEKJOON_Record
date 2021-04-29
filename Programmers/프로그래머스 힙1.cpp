#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> scoville = { 1,2,3,9,10,12 };
	int K = 7;
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> que;
	int min, sec;
	for (int i = 0; i < scoville.size(); i++)
		que.push(scoville[i]);
	while (true) {
		min = que.top();
		que.pop();
		if (que.empty()) {
			answer = -1; break;
		}
		if (min >= K) break;
		sec = que.top();
		que.pop();
		que.push(min + sec * 2);
		answer++;
	}
	cout << answer;
}