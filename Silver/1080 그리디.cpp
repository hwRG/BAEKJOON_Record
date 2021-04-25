#include <iostream>
#include <string>
using namespace std;

int N, M, result;
bool st[50][50], en[50][50];

void change(int y, int x) {
	for (int i = y; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			st[i][j] = !st[i][j];
	result++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++)
			st[i][j] = str[j] - 48;
	}
	for (int i = 0; i < N; i++){
		cin >> str;
		for (int j = 0; j < M; j++)
			en[i][j] = str[j] - 48;
	}
	for (int i = 0; i < N - 2; i++) 
		for (int j = 0; j < M - 2; j++) 
			if(st[i][j] != en[i][j])
				change(i, j);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (st[i][j] != en[i][j]) result = -1;
	cout << result;
}