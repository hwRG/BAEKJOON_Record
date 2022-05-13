#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Memoization
// 4C2는 3C1과 3C2의 합으로 이루어짐

string C[101][101];
int n, m;

string numToString(string a, string b) {
	int sum = 0;
	string ret;
	while (a.size() || b.size() || sum) {
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string memo(int n, int m) {
	if (m == 0 || m == n) 
		return "1";
	string& ret = C[n][m];

	if (ret != "")
		return ret;

	ret = numToString(memo(n - 1, m - 1), memo(n - 1, m));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << memo(n,m);
}