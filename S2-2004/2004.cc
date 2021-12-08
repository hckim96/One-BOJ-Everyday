#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    auto twoNum = [&](long long n) {
        long long two = 0;
        long long tmp = 2;
        while (n / tmp) {
            two += n / tmp;
            tmp *= 2;
        }
        return two;
    };
    auto fiveNum = [&](long long n) {
        long long five = 0;
        long long tmp = 5;
        while (n / tmp) {
            five += n / tmp;
            tmp *= 5;
        }
        return five;
    };

    long long N, M;
    cin >> N >> M;

    cout << min(twoNum(N) - twoNum(N - M) - twoNum(M), fiveNum(N) - fiveNum(N - M) - fiveNum(M)) << '\n';
}