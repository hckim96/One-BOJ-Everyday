#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double answer;

void f(vector<pair<int, int> >& point, int cur, int xSum, int ySum, int selectedNum) {
    if (selectedNum == point.size() / 2) {
        answer = min(answer, sqrt(1LL * xSum * xSum + 1LL * ySum * ySum));
        return;
    }

    if (cur == point.size()) {
        return;
    }

    if (cur - selectedNum > point.size() / 2) {
        return;
    }

    f(point, cur + 1, xSum - 2 * point[cur].first, ySum - 2 * point[cur].second, selectedNum + 1);
    f(point, cur + 1, xSum, ySum, selectedNum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        answer = 1e20;
        int N;
        cin >> N;
        vector<pair<int, int> > point(N);
        int xSum = 0;
        int ySum = 0;

        for (auto & e: point) {
            cin >> e.first >> e.second;
            xSum += e.first;
            ySum += e.second;
        }
        
        f(point, 0, xSum, ySum, 0);
        cout.precision(6);
        cout << fixed << answer << '\n';
    }
}