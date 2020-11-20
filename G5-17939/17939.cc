#include <iostream>
#include <deque>

using namespace std;

#define N_MAX 100000

int N;
int price[N_MAX];

// 극대값
deque<int> localMax;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> price[i];

        if (localMax.empty()) {
            localMax.push_back(price[i]);
        } else {
            while (!localMax.empty() && localMax.back() < price[i]) {
                localMax.pop_back();
            }
            localMax.push_back(price[i]);
        }
    }

    int profit = 0;
    for (int i = 0; i < N; i++) {
        if (localMax.empty()) {
            // 끝까지 내려감 더 안해도 됨
            break;
        }
        if (price[i] < localMax.front()) {
            profit += localMax.front() - price[i];
        } else if (price[i] == localMax.front()) {
            localMax.pop_front();
        }
    }

    cout << profit << "\n";
}