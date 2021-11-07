#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<long long> fib(N + 1);
    fib[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[N] << '\n';
}