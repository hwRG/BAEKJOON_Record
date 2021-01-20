#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;

	cin >> n;
	double* dollar = new double[n];
	for (int i = 0; i < n; i++)
		cin >> dollar[i];
	for (int i = 0; i < n; i++){
		cout << fixed;
		cout.precision(2);
		cout << "$" << dollar[i]*4/5 << endl;
	}
	delete dollar;
}