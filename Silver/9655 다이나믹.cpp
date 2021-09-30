#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i <= 1000; i++) {
		if (N == 0){
			cout << "CY";
			break;
		}
		if (N >= 3) 
			N -= 3;
		else if (N < 3 && N > 0) 
			N -= 1;

		if (N == 0){
			cout << "SK";
			break;
		}
		if (N >= 3) 
			N -= 3;
		else if (N < 3 && N > 0) 
			N -= 1;
	}
}
