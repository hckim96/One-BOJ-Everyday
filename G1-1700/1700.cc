#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> schedule(K);
    vector<int> hole(N, 0);

    for (auto& e: schedule) {
        cin >> e;
    }

    int answer = 0;

    for (int i = 0; i < K; ++i) {
        bool pluggedIn = false;
        bool notUsingHoleExists = false;
        int idx = 0;

        while (idx < N) {
            if (hole[idx] == schedule[i]) {
                pluggedIn = true;
                break;
            }

            if (hole[idx] == 0) {
                notUsingHoleExists = true;
                break;
            }
            ++idx;
        }

        if (pluggedIn) {
            continue;
        }

        if (notUsingHoleExists) {
            hole[idx] = schedule[i];
            continue;
        }

        pair<int, int> tmp = {0, 0};

        for (int j = 0; j < N; ++j) {
            for (int k = i + 1; k < K; ++k) {
                if (hole[j] == schedule[k]) {
                    if (tmp.second < k - i) {
                        tmp = {j, k - i};
                    }
                    break;
                }

                if (k == K - 1) {
                    tmp = {j, INF};
                }
            }
            if (tmp.second == INF) {
                break;
            }
        }

        hole[tmp.first] = schedule[i];
        ++answer;
    }

    cout << answer << '\n';
}