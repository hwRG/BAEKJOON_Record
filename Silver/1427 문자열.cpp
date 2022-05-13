#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	char temp;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[i] < str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	cout << str;
}