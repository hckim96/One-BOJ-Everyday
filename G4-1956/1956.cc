#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define V_MAX 400
#define INF 987654321

vector<vector<int> > distanceArr(V_MAX + 1, vector<int> (V_MAX + 1, INF));

int V, E;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        distanceArr[a][b] = c;
    }

    for (int j = 1; j <= V; j++) {
        for (int i = 1; i <= V; i++) {
            for (int k = 1; k <= V; k++) {
                if (distanceArr[i][k] > distanceArr[i][j] + distanceArr[j][k]) {
                    distanceArr[i][k] = distanceArr[i][j] + distanceArr[j][k];
                }
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= V; i++) {
        answer = min(answer, distanceArr[i][i]);
    }

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << "\n";
    }
}