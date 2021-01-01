#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define N_MAX 15
#define INF 987654321

int N, M, D;
int answer = -1;
vector<pair<int, int> > enemy;

void moveEnemy(vector<pair<int, int> >& enemyCopy) {
    for (auto it = enemyCopy.begin(); it != enemyCopy.end(); it++) {
        if (it -> first == N - 1) {
            enemyCopy.erase(it--);
        } else {
            it -> first++;
        }
    }
}

void playGame(vector<int>& archer, vector<pair<int, int> > enemyCopy) {

    int killed = 0;
    while (!enemyCopy.empty()) {

        set<pair<int, int> > willDie;

        for (auto a : archer) {

            // find nearest
            int dist = INF;
            pair<int, int> coord;

            for (auto e : enemyCopy) {
                int tmpDist = abs(N - e.first) + abs(a - e.second);

                if (tmpDist <= D) {
                    if (tmpDist < dist) {
                        dist = tmpDist;
                        coord = {e.first, e.second};
                    } else if (tmpDist == dist) {
                        if (e.second < coord.second) {
                            coord = {e.first, e.second};
                        }
                    }
                }
            }
            if (dist != INF) {
                willDie.insert(coord);
            }
        }

        // kill
        for (auto it = enemyCopy.begin(); it != enemyCopy.end(); it++) {
            for (auto it2 = willDie.begin(); it2 != willDie.end(); it2++) {
                if (*it == *it2) {
                    killed++;
                    enemyCopy.erase(it--);
                    willDie.erase(it2);
                    break;
                }
            }
        }
        // move
        moveEnemy(enemyCopy);
    }
    answer = max(killed, answer);
}

int main() {
    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            if (num == 1) {
                enemy.push_back({i, j});
            }
        }
    }
    
    // M C 3 
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                vector<int> v {i, j, k};
                playGame(v, enemy);
            }
        }
    }

    cout << answer << "\n";
}