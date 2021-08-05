#include <iostream>
#include <vector>

using namespace std;

bool existAdj(int stat) {
    int tmp = stat & 1;
    stat >>= 1;
    
    while (stat) {
        if (stat & 1 & tmp) {
            return true;
        }
        tmp = stat & 1;
        stat >>= 1;
    }

    return false;
}

bool canPlace(vector<vector<char> >& arr, int r, int stat) {
    for (int j = 0; j < arr[0].size(); ++j) {
        if (arr[r][j] == 'x' && (stat & (1 << j))) {
            return false;
        }
    }

    return true;
}

bool canCheat(int pstat, int stat) {
    return existAdj(pstat | stat);
}

int oneCnt(int stat) {
    int ret = 0;
    while (stat) {
        if (stat & 1) {
            ++ret;
        }
        stat >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<char> > arr(N, vector<char> (M));

        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < M; ++j) {
                arr[i][j] = s[j];
            }
        }

        vector<vector<int> > dp(N, vector<int> (1 << M, 0));
        vector<pair<int, int> > v;

        for (int stat = 0; stat < (1 << M); ++stat) {
            if (existAdj(stat)) {
                continue;
            }

            v.push_back({oneCnt(stat), stat});
        }

        int answer = 0;
        for (auto [cnt, stat]: v) {
            if (canPlace(arr, 0, stat)) {
                dp[0][stat] = cnt;
                answer = max(answer, cnt);
            }
        }

        for (int i = 1; i < N; ++i) {
            for (auto [cnt, stat]: v) {
                if (!canPlace(arr, i, stat)) {
                    continue;
                }
                for (auto [pcnt, pstat]: v) {
                    if (canPlace(arr, i - 1, pstat) && !canCheat(pstat, stat)) {
                        dp[i][stat] = max(dp[i][stat], dp[i - 1][pstat] + cnt);
                    }
                }

                if (i == N - 1) {
                    answer = max(answer, dp[i][stat]);
                }
            }
        }

        cout << answer << '\n';
    }
}