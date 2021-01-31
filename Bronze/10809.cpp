#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int alpha[26];
	for (int i = 0; i < 26; i++) 
		alpha[i] = -1;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < S.length(); j++) {
			if (S[j] == char(i + 97)) {
				alpha[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << ' ';
}