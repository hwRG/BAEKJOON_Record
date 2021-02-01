#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct alphabet {
	char alphabet;
	long long index = 0;
};

bool cmp(alphabet a, alphabet b) {
	return a.index > b.index;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	alphabet alp[26];
	for (int i = 0; i < 26; i++)
		alp[i].alphabet = char(i + 65);

	long long N, total = 0, descend = 9;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int count = 1;
		cin >> str;
		for (int j = str.length() - 1; j >= 0; j--) {
			for (int k = 0; k < 26; k++) {
				if (alp[k].alphabet == str[j]) {
					alp[k].index += count;
					count *= 10;
					break;
				}
			}
		}
	}
	sort(alp, alp + 26, cmp);
	for (int i = 0; i < 26; i++) {
		if (alp[i].index == 0) break;
		alp[i].index *= descend;
		total += alp[i].index;
		descend--;
	}
	cout << total;
}