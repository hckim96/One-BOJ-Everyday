#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    int min_ = 1e9;
    int max_ = 0;

    while (N--) {
        int num;
        cin >> num;
        min_ = min(min_, num);
        max_ = max(max_, num);
    }
    cout << max_ - min_ << '\n';
}