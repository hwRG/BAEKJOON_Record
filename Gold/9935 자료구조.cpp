#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string start, check, result;
	cin >> start >> check;
	int ch = check.size(), cur = 0;

	for (int i = 0; i < start.size(); i++) {
		result += start[i];
		if (result[result.size() - 1] == check[ch - 1]) {
			for (int j = 0; j < ch; j++) {
				if (result[result.size() - 1 - j] != check[ch - 1 - j])
					break;
				else
					cur++;
			}
			if (cur == ch)
				for (int j = 0; j < ch; j++) result.pop_back();
			cur = 0;
		}
	}
	if (result == "") cout << "FRULA";
	else cout << result;
}