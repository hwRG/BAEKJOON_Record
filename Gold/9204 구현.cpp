#include <iostream>
using namespace std;

struct pos {
	int wid;
	char len;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		pos start, end, temp;
		int LenMove, WidMove;

		cin >> start.len >> start.wid >> end.len >> end.wid;
		if (start.len % 2 == end.len % 2 && start.wid % 2 != end.wid % 2)
			cout << "Impossible" << '\n';
		else if (start.len % 2 != end.len % 2 && start.wid % 2 == end.wid % 2)
			cout << "Impossible" << '\n';
		else if (start.len == end.len && start.wid == end.wid)
			cout << "0 " << start.len << ' ' << start.wid << '\n';
		else if (abs(start.len - end.len) == abs(start.wid - end.wid))
			cout << "1 " << start.len << ' ' << start.wid << ' ' << end.len << ' ' << end.wid << '\n';

		else {
			cout << "2 " << start.len << ' ' << start.wid << ' ';
			temp.len = start.len, temp.wid = start.wid;
			if (abs(start.len - end.len) > abs(start.wid - end.wid)) {
				if (start.len - end.len < 0) LenMove = 1;
				else LenMove = -1;
				WidMove = 1;
				while (1) {
					temp.len += LenMove, temp.wid += LenMove;
					if (temp.wid > 8) {
						temp.len = start.len, temp.wid = start.wid;
						WidMove = -1;
					}
					else if (abs(temp.len - end.wid) == abs(temp.wid - end.wid)) {
						cout << temp.len << ' ' << temp.wid << ' ' << end.len << ' ' << end.wid << '\n';
						break;
					}
				}
			}
			else {
				if (start.wid - end.wid < 0) WidMove = 1;
				else WidMove = -1;
				LenMove = 1;
				while (1) {
					temp.len += LenMove, temp.wid += WidMove;
					if (temp.len > 'H') {
						temp.len = start.len, temp.wid = start.wid;
						LenMove = -1;
					}
					else if (abs(temp.len - end.len) == abs(temp.wid - end.wid)) {
						cout << temp.len << ' ' << temp.wid << ' ' << end.len << ' ' << end.wid << '\n';
						break;
					}
				}
			}
		}
	}
}