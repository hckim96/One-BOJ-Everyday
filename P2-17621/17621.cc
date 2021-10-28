#include <iostream>
#include <vector>

using namespace std;

enum {
    AIR,
    GROUND,
    NOTHING
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int> > v(M + 1);
    vector<pair<int, int> > lr(M + 2, {N + 1, N + 1});
    vector<pair<int, int> > lr2(M + 2, {N + 1, N + 1});
    vector<int> state(M + 1, NOTHING);

    for (int j = 1; j <= M; ++j) {
        cin >> v[j].first >> v[j].second;
        
        if (v[j].second == N) {
            state[j] = GROUND;
            // 바닥 붙
            lr[j].first = min(lr[j - 1].first, v[j].first);
        } else if (v[j].second == 0) {
            v[j] = {N + 1, N + 1};
            // 비었음
            state[j] = NOTHING;
            lr[j].first = lr[j - 1].first;
        } else {
            // 공중
            state[j] = AIR;
            lr[j].first = lr[j - 1].first;
            if (state[j - 1] != AIR || v[j - 1].second + 1 < v[j].first) {
                lr2[j].first = v[j].first;
            } else {
                lr2[j].first = min(lr2[j - 1].first, v[j].first);
            }
        }
    }
    for (int j = M; j >= 1; --j) {
        if (state[j] == GROUND) {
            // 바닥 붙
            lr[j].second = min(lr[j + 1].second, v[j].first);
        } else if (state[j] == NOTHING) {
            // 비었음
            lr[j].second = lr[j + 1].second;
        } else {
            // 공중
            lr[j].second = lr[j + 1].second;
            if (state[j + 1] != AIR || v[j + 1].second + 1 < v[j].first) {
                lr2[j].second = v[j].first;
            } else {
                lr2[j].second = min(lr2[j + 1].second, v[j].first);
            }
        }
    }

    long long answer = 0;
    for (int j = 1; j <= M; ++j) {
        if (state[j] != AIR) {
            answer += v[j].first - max(lr[j].first, lr[j].second);
        } else {
            answer += v[j].first - min(max(lr[j].first, lr[j].second), max(lr2[j].first, lr2[j].second)) + N + 1 - max(v[j].second + 1, max(lr[j].first, lr[j].second));
        }
    }
    cout << answer << '\n';
}