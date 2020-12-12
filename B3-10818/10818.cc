#include <iostream>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int max, min;

    max = -INF;
    min = INF;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (max < num) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }
    cout << min << " " << max << "\n";
}