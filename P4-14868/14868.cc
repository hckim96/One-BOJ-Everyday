#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

vector<int> p;

int myFind(int n) {
    if (p[n] == 0) {
        return n;
    }
    return p[n] = myFind(p[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N, K;
    cin >> N >> K;

    vector<vector<int> > section(N + 1, vector<int> (N + 1, 0));
    queue<pair<int, int> > nowQ;
    queue<tuple<int, int, int> > willQ;
    
    int seq = 1;
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        nowQ.push({x, y});
        section[x][y] = seq++; 
    }
    
    p.resize(K + 1, 0);
    int time = 0;
    int cnt;
    while (K >= 2) {
        while (!nowQ.empty()) {
            auto [fx, fy] = nowQ.front();
            nowQ.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = fx + dr[dir];
                int ny = fy + dc[dir];

                if (nx <= 0 || nx > N || ny <= 0 || ny > N) {
                    continue;
                }

                if (section[nx][ny]) {
                    int p1 = myFind(section[fx][fy]);
                    int p2 = myFind(section[nx][ny]);

                    if (p1 == p2) {
                        continue;
                    }

                    p[p1] = p2;
                    if (--K == 1) {
                        cout << time << '\n';
                        return 0;
                    }
                    continue;
                }

                willQ.push({nx, ny, section[fx][fy]});
            }
        }
        ++time;

        while (!willQ.empty()) {
            auto [fx, fy, fs] = willQ.front();
            willQ.pop();
            if (section[fx][fy]) {
                int p1 = myFind(fs);
                int p2 = myFind(section[fx][fy]);

                if (p1 == p2) {
                    continue;
                }

                p[p1] = p2;
                if (--K == 1) {
                    cout << time << '\n';
                    return 0;
                }
            } else {
                section[fx][fy] = fs;
                nowQ.push({fx, fy});
            }
        }
    }

    cout << time << '\n';
}