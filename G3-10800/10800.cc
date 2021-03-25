#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // size, color, player
    vector<tuple<int, int, int> > ball(N);

    for (int i = 1; i <= N; ++i) {
        int color, size;
        cin >> color >> size;
        ball[i - 1] = {size, color, i};
    }

    sort(ball.begin(), ball.end());

    vector<int> colorSum(N + 1, 0);
    vector<int> prevColorSum(N + 1, 0);
    vector<int> answer(N + 1);
    int totalSum = 0;
    int prevTotalSum = 0;
    int lastSize = 0;

    for (auto e: ball) {
        auto [size, color, player] = e;
        if (lastSize == size) {
            answer[player] = prevTotalSum - prevColorSum[color];
            colorSum[color] += size;
            totalSum += size;
        } else {
            answer[player] = totalSum - colorSum[color];
            prevColorSum = colorSum;
            prevTotalSum = totalSum;
            totalSum += size;
            colorSum[color] += size;
            lastSize = size;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << answer[i] << '\n';
    }
}