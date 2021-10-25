#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    map<int, int> x;
    map<int, int> y;

    pair<int, int> first;
    pair<int, int> prev;

    for (int i = 0; i < N; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;

        if (i == 0) {
            first = p;
            prev = p;
            continue;    
        }

        if (prev.second == p.second) {
            ++x[min(p.first, prev.first)];
            --x[max(p.first, prev.first)];
        } else {
            ++y[min(p.second, prev.second)];
            --y[max(p.second, prev.second)];
        }
        prev = p;
    }

    pair<int, int> p = first;
    if (prev.second == p.second) {
        ++x[min(p.first, prev.first)];
        --x[max(p.first, prev.first)];
    } else {
        ++y[min(p.second, prev.second)];
        --y[max(p.second, prev.second)];
    }

    int answer = 0;
    int tmp = 0;
    for (auto it = x.begin(); it != x.end(); ++it) {
        tmp += it -> second;
        answer = max(answer, tmp);
    }

    tmp = 0;
    for (auto it = y.begin(); it != y.end(); ++it) {
        tmp += it -> second;
        answer = max(answer, tmp);
    }

    cout << answer << '\n';
}