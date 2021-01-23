#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 1500

int N;
int arr[N_MAX][N_MAX] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    priority_queue<tuple<int, int, int> > pq;

    for (int j = 0; j < N; j++) {
        pq.push({arr[N - 1][j], N - 1, j});
    }

    int cnt = 0;

    while (true) {
        auto [fv, fr, fc] = pq.top();
        pq.pop();
        cnt++;

        if (cnt == N) {
            cout << fv << "\n";
            return 0;
        }

        if (fr == 0) {
            continue;
        }

        pq.push({arr[fr - 1][fc], fr - 1, fc});
    }

}