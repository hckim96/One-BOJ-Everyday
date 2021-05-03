#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};

bool cmp(tuple<int, int, int, int, int> t1, tuple<int, int, int, int, int> t2) {
    return get<4>(t1) > get<4>(t2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, M;
    cin >> R >> C >> M;

    vector<tuple<int, int, int, int, int> > shark(M);
    vector<vector<int> > arr(R + 1, vector<int> (C + 1, -1));

    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2) {
            s %= 2 * (R - 1);
        } else {
            s %= 2 * (C - 1); 
        }

        shark[i] = {r, c, s, d, z};
    } 

    sort(shark.begin(), shark.end(), cmp);
    for (int i = 0; i < M; ++i) {
        arr[get<0>(shark[i])][get<1>(shark[i])] = i;
    }
    
    int fishermanCol = 0;
    int answer = 0;
    while (++fishermanCol <= C) {
        for (int r = 1; r <= R; ++r) {
            if (arr[r][fishermanCol] != -1) {
                answer += get<4>(shark[arr[r][fishermanCol]]);
                get<4>(shark[arr[r][fishermanCol]]) = 0;
                break;
            }
        }

        for (auto it = shark.begin(); it != shark.end(); ++it) {
            auto [r, c, s, d, z] = *it;
            if (z == 0) {
                continue;
            }
            int tmp = s;

            int nr = r;
            int nc = c;
            int nd = d;

            while (tmp--) {
                nr += dr[nd];
                nc += dc[nd];
                if (nr < 1 || nr > R || nc < 1 || nc > C) {
                    nr -= dr[nd];
                    nc -= dc[nd];
                    if (nd == 1) {
                        nd = 2;
                    } else if (nd == 2) {
                        nd = 1;
                    } else if (nd == 3) {
                        nd = 4;
                    } else {
                        nd = 3;
                    }
                    ++tmp;
                }
            }
            
            *it = {nr, nc, s, nd, z};
        }

        arr = vector<vector<int> > (R + 1, vector<int> (C + 1, -1));
        for (auto it = shark.begin(); it != shark.end(); ++it) {
            auto & [r, c, d, s, z] = *it;
            if (z == 0) {
                continue;
            }

            if (arr[r][c] == -1) {
                arr[r][c] = it - shark.begin();
            } else {
                z = 0;
            }
        }
    }

    cout << answer << '\n';
}
