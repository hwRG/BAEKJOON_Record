// ¾ÆÁ÷ ´úÇ°

#include <iostream>
#include <string>
using namespace std;

int main() {
	int R, C;
	cin >> R >> C;
	string line;
	char** list = new char*[R];
	for (int i = 0; i < R; i++) 
		list[i] = new char[C];

	for (int i = 0; i < R; i++) {
		cin >> line;
		for (int j = 0; j < C; j++) 
			list[i][j] = line[j];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (list[i][j] == 'S') {
				if (list[i + 1][j] == 'W' && list[i - 1][j] == 'W' && list[i][j + 1] == 'W' && list[i][j - 1] == 'W') {
					cout << 0 << endl;
				}
			}
		}
	}

	return 0;
}
/*
if(list[i][j] != '.' && list[i + 1][j] != '.') {
	if (list[i][j] != list[i + 1][j]) {
		cout << 0;
		return 0;
	}
}
*/