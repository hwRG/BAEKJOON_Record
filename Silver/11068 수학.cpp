#include <iostream>
#include <cmath>
using namespace std;

int list[64];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int T, num;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> num; 

		for (int i = 2; i <= 64; i++) { // i는 i진수
			bool flag = false;
			int nowNum = num, squ = 1;

			while (pow(i,squ) < num) 
				squ++; // squ는 최대 지수 ex) 37은 5의 2제곱까지 (squ는 3임)

			for (int j = squ-1; j >= 0; j--) { // squ는 3 -> j는 2, 1 
				for (int k = 0; k < i; k++) {
					if (nowNum < pow(i, j) * (k + 1)){
						list[j] = k;
						nowNum -= pow(i, j) * k;
						break;
					}
				}
			}
			for (int q = 0; q <= squ / 2; q++) 
				if (list[q] != list[squ - q - 1])
					flag = true;

			if (!flag) {
				cout << 1 << '\n';
				break;
			}
			if (i == 64 && flag) 
				cout << 0 << '\n';
		}
	}
}