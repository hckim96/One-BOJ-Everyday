#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int toInt(string& s) {
    int hour = stoi(s.substr(0, 2));
    hour *= 60;
    int min = stoi(s.substr(2, 2));
    return hour + min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, T, P;
    cin >> N >> T >> P;

    // start, useTime
    struct cmp {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p2.second < p1.second;
            }
            return p2.first < p1.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq; 
    while (T--) {
        string s, e;
        cin >> s >> e;

        int si, ei;
        si = toInt(s);
        ei = toInt(e);
        pq.push({si, ei - si});
    }

    vector<int> endTime(N + 1, 0);

    auto f = [&](int time) -> int {
        vector<int> v;
        for (int i = 1; i <= N; ++i) {
            if (endTime[i] > time) {
                v.push_back(i);
            }
        }
        if (v.empty()) return 1;

        int ret;
        int dist = 0;

        for (int i = 1; i <= N; ++i) {
            if (endTime[i] > time) continue;
            int minDist = N;


            for (auto e: v) {
                if (minDist > abs(i - e)) {
                    minDist = abs(i - e);
                }
            }
            if (dist < minDist) {
                dist = minDist;
                ret = i;
            } else if (dist == minDist) {
                if (ret > i) ret = i;
            }
        }
        return ret;
    };

    int answer = 12 * 60;

    while (pq.size()) {
        auto [s, t] = pq.top();
        pq.pop();
        auto seat = f(s);
        endTime[seat] = s + t;
        if (seat == P) {
            answer -= t;
        }
    }
    cout << answer << '\n';    
}