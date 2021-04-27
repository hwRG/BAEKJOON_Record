#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0, total = 0;
    queue<int> que;
    while (1) {
        if (que.size() == bridge_length || answer >= bridge_length + 1) {
            int index = que.front();
            total -= index;
            que.pop();
        }
        if (total + truck_weights[count] <= weight) {
            que.push(truck_weights[count]);
            total += truck_weights[count];
            count++;
        }
        else
            que.push(0);
        if (count == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        answer++;
    }
    answer++;
    return answer;
}

int main() {
    //vector<int> v = { 7,4,5,6 }; cout << solution(2, 10, v);
    vector<int> v = { 10 }; cout << solution(100, 100, v);

}