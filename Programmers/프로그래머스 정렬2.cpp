#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> numbers = { 0,0,0,0 };
	string answer = "";
	vector<pair<string, string>> list;
	int sum = 0;
	for(auto i : numbers)
		sum += i;
	if (sum == 0) return 0;

	for (int i : numbers) 
		list.push_back({ to_string(i), to_string(i) });
	for (int i = 0; i < list.size(); i++) {
		int j = 0;
		while(list[i].first.size() != 6){
			list[i].first += list[i].second[j % list[i].second.size()];
			j++;
		}
	}
	
	sort(list.begin(), list.end());
	
	for (int i = list.size() - 1; i > -1; i--)
		answer += list[i].second;

	cout << answer;
}