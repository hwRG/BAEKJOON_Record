#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //vector<string> phone_book = { "119", "97674223", "1195524421" };
    vector<string> phone_book = { "123","456","789" };
    //vector<string> phone_book = { "12","123","1235","567","88" };
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1;i++) 
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].length())) 
            answer = false;
    cout << answer;
}