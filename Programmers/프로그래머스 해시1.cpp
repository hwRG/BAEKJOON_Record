#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<string> participant = { "mislav", "stanko", "mislav", "ana", "stanko" };
	vector<string> completion = { "stanko", "ana", "mislav", "mislav" };
	string answer;

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size(); i++) {
		if (i == participant.size()-1) {
			answer = participant[i];
			break;
		}
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}
	/*
	bool* overlap = new bool[completion.size()];
	for (int i = 0; i < completion.size(); i++) 
		overlap[i] = true;
	for (auto p : participant) {
		bool flag = true;
		int count = 0;
		for (auto c : completion) {
			if (p == c && overlap[count]) {
				flag = false;
				overlap[count] = false;
				break;
			}
			count++;
		}
		if (flag == true) {
			answer = p;
			break;
		}
	}*/
	cout << answer;

}