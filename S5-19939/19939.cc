#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    if (N < K * (K + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    cout <<  K - 1 + ((N - (K * (K + 1) / 2)) % K != 0)<< '\n';
}