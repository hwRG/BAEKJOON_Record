#include <iostream>
using namespace std;

int picture[101][101];

int main() {
	int N, M, count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int minX, minY, maxX, maxY;
		cin >> minX >> minY >> maxX >> maxY;
		for (int x = minX; x <= maxX; x++) 
			for (int y = minY; y <= maxY; y++) 
				picture[x][y]++;
	}
	for (int i = 1; i < 101; i++) 
		for (int j = 1; j < 101; j++) 
			if (picture[i][j] > M)
				count++;
	cout << count;
}