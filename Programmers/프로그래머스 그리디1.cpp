#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 5;
	bool ok[31];
	vector<int> lost = { 3,2,4 };
	vector<int> reserve = { 1, 3, 5 };
	int answer = 0;

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
			}
		}
	}
	answer = n - lost.size();

	for (auto i : lost) {
		for (auto j : reserve) {
			if (i - 1 == j && ok[j]) {
				answer++;
				ok[j] = false;
				break;
			}
			else if (i + 1 == j && ok[j]) {
				answer++;
				ok[j] = false;
				break;
			}
		}
	}
	cout << answer;
}