#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



	int T, N;
	string obj, cat;
	cin >> T;

	for (int t = 0; t < T; t++) {
		// string은 category, int는 count
		map<string, int> mapped;
		int result = 1; // 곱셈을 더할 예정으로 1로 초기화
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> obj >> cat;

			if (mapped.find(cat) == mapped.end()) 
				mapped[cat] = 1;
			else 
				mapped[cat]++;
		}

		for(auto map : mapped)
			result *= (map.second + 1);

		cout << result - 1 << '\n';
	}
}