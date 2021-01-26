#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int alphabet[26][2];

int main() {
	string str[10];
	for (int i = 0; i < 26; i++) 
		alphabet[i][0] = i + 65;

	int N, max = 0, num = 9, total = 0;
	cin >> N;
	int count = N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		if (str[i].length() > max) max = str[i].length();
	}
	int current = max;
	for(int a = 0; a < max; a++){
		for (int i = 0; i < N; i++) { 
			if (str[i].length() == current) { 
				for (int j = 0; j < 26; j++) { 
					if (str[i][0] == alphabet[j][0]) {
						if (alphabet[j][1] == 0){
							alphabet[j][1] = num;
							num--;
						}
						total += alphabet[j][1] * pow(10, current - 1);
						str[i].erase(0, 1);
						break;
					}
				}
			}
		}
		current--;
	}
	cout << total;
}