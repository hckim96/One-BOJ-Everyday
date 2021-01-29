#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    while (T--) {
        int N, D, C;
        cin >> N >> D >> C;

        vector<vector<pair<int ,int> > > dep(N + 1, vector<pair<int ,int> > ());

        for (int i = 0; i < D; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            dep[b].push_back({a, s});
        }
        
        vector<int> time(N + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        time[C] = 0;
        pq.push({0, C});


        while (!pq.empty()) {
            auto [tt, tc] = pq.top();
            pq.pop();
            
            if (tt > time[tc]) {
                continue;
            }

            for (auto e: dep[tc]) {
                if (time[e.first] > time[tc] + e.second) {
                    time[e.first] = time[tc] + e.second;
                    pq.push({time[e.first], e.first});
                }
            }
        }

        int answerTime = -1;
        int answerCnt = 0;       
        for (int i = 1; i <= N; i++) {
            if (time[i] != INF) {
                answerCnt++;
                answerTime = answerTime > time[i] ? answerTime : time[i];
            }
        }

        cout << answerCnt << " " << answerTime << "\n";
    }
}