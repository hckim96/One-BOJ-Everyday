#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;

#define N_MAX 3000

// r c R
vector<tuple<double, double, double> > camp;
int adjacencyMatrix[N_MAX][N_MAX] = {0};
int T, N;

void makeAdjacencyMatrix(int campNum) {
    fill(&adjacencyMatrix[0][0], &adjacencyMatrix[0][0] + (N_MAX * N_MAX), 0);

    for (int i = 0; i < campNum; i++) {
        for (int j = i + 1; j < campNum; j++) {

            double r1, c1, R1, r2, c2, R2;
            tie(r1, c1, R1) = camp[i];
            tie(r2, c2, R2) = camp[j];
            double distance = sqrt(pow(r1 - r2, 2) + pow(c1 - c2, 2));
            double sumOfRange = R1 + R2;

            if (sumOfRange >= distance) {
                adjacencyMatrix[i][j] = 1;
                adjacencyMatrix[j][i] = 1;
            }

        }
    }
}

int visited[N_MAX] = {0};
int cnt = 0;
void dfs(int idx) {

    for (int i = 0; i < N; i++) {
        if (adjacencyMatrix[idx][i] == 0) {
            continue;
        }

        if (visited[i] == 1) {
            continue;
        }

        visited[i] = 1;
        dfs(i);
    }
}

int main() {

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        
        camp.reserve(N * sizeof(tuple<double, double, double>));
        cnt = 0;
        fill_n(visited, N, 0);

        for (int j = 0; j < N; j++) {
            int c, r, R;
            cin >> c >> r >> R;
            camp.push_back({r, c, R});
        }

        makeAdjacencyMatrix(N);

        for (int k = 0; k < N; k++) {
            if (visited[k] == 0) {
                cnt++;
                dfs(k);
            }
        }

        camp.clear();
        vector<tuple<double, double, double> > ().swap(camp);
        cout << cnt << "\n";
    }


    return 0;
}