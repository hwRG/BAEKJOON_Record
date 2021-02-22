#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	int count = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c' && str[i + 1] == '=') {
			count++;
			i++;
		}
		else if (str[i] == 'c' && str[i + 1] == '-') {
			count++;
			i++;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			count++;
			i += 2;
		}
		else if (str[i] == 'd' && str[i + 1] == '-') {
			count++;
			i++;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j') {
			count++;
			i++;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j') {
			count++;
			i++;
		}
		else if (str[i] == 's' && str[i + 1] == '=') {
			count++;
			i++;
		}
		else if (str[i] == 'z' && str[i + 1] == '=') {
			count++;
			i++;
		}
		else count++;
	}
	cout << count;
}