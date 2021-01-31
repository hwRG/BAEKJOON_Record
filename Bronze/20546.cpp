#include <iostream>
using namespace std;

int main() {
	int money;
	int compare[13], quantityJ = 0, quantityS = 0, totalJ = 0, totalS = 0;
	int stock[14];
	cin >> money;
	int sung = money, june = money;
	for (int i = 0; i < 14; i++)
		cin >> stock[i];

	for (int i = 0; i < 14; i++) {
		if (june >= stock[i]) {
			while (june >= quantityJ * stock[i]) 
				quantityJ++;
			quantityJ--;
			june -= quantityJ * stock[i];
			totalJ += quantityJ;
			quantityJ = 0;
		}
	}
	june += totalJ * stock[13];


	for (int i = 0; i < 13; i++) {
		if (stock[i + 1] > stock[i]) compare[i] = 1;
		else if (stock[i + 1] < stock[i]) compare[i] = 0;
		else compare[i] = -1;
	}
	for (int i = 0; i < 13; i++) {
		if (compare[i] == 0 && compare[i + 1] == 0 && compare[i + 2] == 0) {
			while (sung >= quantityS * stock[i + 3])
				quantityS++;
			quantityS--;
			sung -= quantityS * stock[i + 3];
			totalS += quantityS;
			quantityS = 0;
		}
		else if (compare[i] == 1 && compare[i + 1] == 1 && compare[i + 2] == 1) {
			if (totalS != 0) {
				sung += stock[i + 3] * totalS;
				totalS = 0;
			}
		}
	}
	sung += totalS * stock[13];

	if (june > sung) cout << "BNP";
	else if (june < sung) cout << "TIMING";
	else cout << "SAMESAME";
}