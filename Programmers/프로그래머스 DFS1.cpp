#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> numbers, int& answer, int target, int count = 0, int sum = 0) {
	if (count == numbers.size() - 1) {
		if (sum + numbers[count] == target) answer++;
		if (sum - numbers[count] == target) answer++;
		return;
	}
	dfs(numbers, answer, target, count + 1, sum + numbers[count]);
	dfs(numbers, answer, target, count + 1, sum - numbers[count]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;
	int answer = 0;
	dfs(numbers, answer, target);

	cout << answer;
}