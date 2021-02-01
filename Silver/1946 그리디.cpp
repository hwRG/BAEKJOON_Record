#include <iostream>
#include <algorithm>
using namespace std;

struct applicant {
	int first, second;
};

bool cmp(applicant a, applicant b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	applicant app[100001];
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int count = N;
		for (int j = 0; j < N; j++) 
			cin >> app[j].first >> app[j].second;
		sort(app, app + N, cmp);

		int compare = app[0].second;
		for (int j = 1; j < N; j++) {
			if (app[j].second < compare)
				compare = app[j].second;
			else
				count--;
		}
		cout << count << '\n';
	}
}