#include <iostream>
using namespace std;

int list[200002];

void swab(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, index, count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> index;
		if (index == 0) {
			if (count == 0) {
				cout << 0 << '\n';
				continue;
			}
			cout << list[1] << '\n';

			swab(list[1], list[count]);
			list[count] = 0;
			count--;

			int start = 1, better;
			while (start < count) {
				(list[start * 2] > list[start * 2 + 1]) ? better = start * 2 : better = start * 2 + 1;
				if (list[start] < list[better]) 
					swab(list[start], list[better]);
				else 
					break;
				start = better;
			}

		}
		else {
			count++;
			list[count] = index;
			
			int now = count;
			while (list[now] > list[now / 2] && now > 1) {
				swab(list[now], list[now / 2]);
				now /= 2;
			}
		}
	}
}