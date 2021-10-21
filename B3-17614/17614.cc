#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    long long answer = 0;
    for (int i = 1; i <= N; ++i) {
        int tmp = i;
        while (tmp) {
            if (tmp % 10 != 0 && tmp % 10 % 3 == 0) {
                ++answer;
            }
            tmp /= 10;
        }
    }
    cout << answer << '\n';
}