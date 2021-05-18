#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > point(N);
    vector<vector<double> > dist(N, vector<double> (N, 0));

    for (auto & e: point) {
        cin >> e.first >> e.second;
    }

    pair<int, int> answer;
    double minDist = 1e5;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            dist[j][i] = dist[i][j] = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
        }
    }

    for (int i = 0; i < N; ++i) {
        double maxDist = 0;
        for (int j = 0; j < N; ++j) {
            if (maxDist < dist[i][j]) {
                maxDist = dist[i][j];
            }
        }
        if (minDist > maxDist) {
            minDist = maxDist;
            answer = point[i];
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
}
