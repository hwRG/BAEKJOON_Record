#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int wordList[26][2], top, spot = -1;
	string word;

	for (int i = 0; i < 26; i++) {
		wordList[i][0] = i + 65;
		wordList[i][1] = 0;
	}

	cin >> word;
	for(int i = 0; i < word.length(); i++){
		if (word[i] >= 97 && word[i] <= 122) 
			word[i] = word[i] - 32;
		for (int j = 0; j < 26; j++) 
			if (wordList[j][0] == word[i]) 
				wordList[j][1]++;
	}
	top = wordList[0][1];
	for (int i = 0; i < 26; i++) {
		if (top < wordList[i][1]){
			top = wordList[i][1];
			spot = i;
		}
	}
	if (spot == -1) 
		spot = 0;

	for (int i = 0; i < 26; i++){
		if (top == wordList[i][1]){
			if (i == spot)
				continue;
			cout << '?' << endl;
			return 0;
		}
	}
	cout << (char)wordList[spot][0] << endl;

	return 0;
}
