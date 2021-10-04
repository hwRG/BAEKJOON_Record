#include <iostream>
using namespace std;

int list[500000], n, m;

int find(int index) {
	if (list[index] == index) 
		return index;
	else 
		return list[index] = find(list[index]);
}

void makeUnion(int fir, int sec) {
	if (fir > sec)
		list[sec] = fir;
	else if (fir < sec)
		list[fir] = sec;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int fir, sec, result = 0;
	bool flag = false;
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		list[i] = i;

	for (int t = 0; t < m; t++) {
		cin >> fir >> sec;
		if (flag)
			continue;
		int parF = find(fir);
		int parS = find(sec);

		if (parF != parS) 
			makeUnion(parF, parS);

		else {
			result = t + 1;
			flag = true;
		}
	}

	cout << result;
	return 0;
}