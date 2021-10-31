#include <iostream>
#include <string>
#include <vector>
using namespace std;

string N, result;
int check[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int total = 0;
	bool flag = false, zero_now = false;
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '0') zero_now = true;
		total += N[i] - '0';
		check[N[i] - '0'] += 1;
	}

	if (zero_now){
		if (total % 3 != 0)
			flag = true;
		else {
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < check[i]; j++) {
					result += (char)(i + 48);
				}
			}
		}
	}
	if (flag || !zero_now)
		cout << -1;
	else
		cout << result;

}


// 조합으로 하려했으나 문제 힌트로 접근 변경
/*
void DFS(int s, int L) {
	if (N.size() == L) {
		string num;
		for (int i = 0; i < N.size(); i++)
			if (check[i])
				num += N[i];
		results.push_back(stoi(num));
	}

	for (int i = L; i < N.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		DFS(i, L + 1);
		check[i] = false;
	}

}
*/