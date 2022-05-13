#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, count = 0;
	string temp;
	vector<string> input, result;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < N + M - 1; i++) 
		if (input[i] == input[i + 1]) 
			result.push_back(input[i]);

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) 
		cout << result[i] << '\n';
}
/*
for (int i = 0; i < M; i++) {
		cin >> temp;
		look.push_back(temp);
	}
	sort(look.begin(), look.end());
	int cur = 0;
	for (int i = 0; i < N; i++) {
		for (int j = cur; j < M; j++) {
			if (listen[i] == look[j]) {
				result.push_back(listen[i]);
				count++;
				cur = j;
				break;
			}
		}
	}
	*/