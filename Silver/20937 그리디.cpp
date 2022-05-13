#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<bool> c[50001];
bool flag[50001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, count = 0, index;
	vector<int> search;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> index;
		c[index].push_back(1);
		if (!flag[index]) {
			search.push_back(index);
			flag[index] = true;
		}
	}
	sort(search.begin(), search.end());
	int i = 0;
	while(i < search.size()) {
		stack<int> stack;
		for (int j = i; j <= search.size()-1; j++) {
			if (c[search[j]].size() != 0) {
				stack.push(search[j]);
				c[search[j]].pop_back();
			}
		}
		if (c[search[i]].empty()) i++;
		if (stack.empty())
			break;
		count++;
	}
	cout << count;
}