#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        int tmp = i;
        int mod = 0;

        while (tmp) {
            mod += tmp % 10;
            tmp /= 10;
        }

        if (i % mod == 0) ++answer;
    }
    cout << answer << '\n';
}