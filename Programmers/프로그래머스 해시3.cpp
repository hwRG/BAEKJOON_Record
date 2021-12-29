#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, string>> table;

int main() {
	vector<vector<string>> clothes = { {"yellowhat", "headgear"},
										{"bluesunglasses", "eyewear"},
										{"green_turban", "headgear" }};
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) {
		bool flag = false;
		int target = 0;
		for (int j = 0; j < table.size(); j++) {
			if (table[j].second == clothes[i][1]){
				flag = true;
				target = j;
			}
		}
		if (!flag)
			table.push_back({ 1, clothes[i][1] });
		else
			table[target].first++;
	}

	for (int i = 0; i < table.size(); i++) 
		answer *= (table[i].first+1);
	answer--;
	cout << answer;
	return answer;
}