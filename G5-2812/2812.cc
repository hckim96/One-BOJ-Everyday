#include <iostream>
#include <deque>

using namespace std;

int N, K;
string number;
deque<char> answer;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> N >> K >> number;

    int deleted = 0;

    answer.push_back(number[0]);

    // 큰 자리수 에서 부터 최대한 많이 지우기
    for (int i = 1; i < N; i++) {
        while(!answer.empty() && answer.back() - '0' < number[i] - '0') {
            if (deleted == K) {
                break;
            }
            answer.pop_back();
            deleted++;
        }
        answer.push_back(number[i]);
    }

    for (int i = 0; i < N - K; i++) {
        cout << answer[i];
    }
    cout << "\n";
}