#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    deque<int> dq;
    int N, M;

    cin >> N >> M;

    vector<int> v(M);
    for (auto& e: v) cin >> e;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    int answer = 0;

    for (auto e: v) {
        auto it = find(all(dq), e);
        answer += min(int(it - dq.begin()), int(dq.size() - (it - dq.begin())));

        while (dq.front() != e) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        dq.pop_front();
    }

    cout << answer << '\n';    
}