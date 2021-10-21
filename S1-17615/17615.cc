#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    string s;
    cin >> s;

    long long answer = 1e18;

    int cnt;
    long long tmp;

    tmp = 0;
    cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'R') {
            ++cnt;
        } else {
            tmp += cnt;
            cnt = 0;
        }
    }
    answer = min(tmp, answer);
    tmp = 0;
    cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == 'R') {
            ++cnt;
        } else {
            tmp += cnt;
            cnt = 0;
        }
    }
    answer = min(tmp, answer);
    tmp = 0;
    cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'B') {
            ++cnt;
        } else {
            tmp += cnt;
            cnt = 0;
        }
    }
    answer = min(tmp, answer);
    tmp = 0;
    cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == 'B') {
            ++cnt;
        } else {
            tmp += cnt;
            cnt = 0;
        }
    }
    answer = min(tmp, answer);

    cout << answer << '\n';
}