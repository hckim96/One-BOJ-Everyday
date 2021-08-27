#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, c, f;
    Edge* reverse;

    int residual() {
        return c - f;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<vector<Edge*> > adj(52);

    while (N--) {
        int n1, n2, c;
        char cn1, cn2;
        cin >> cn1 >> cn2 >> c;

        if (cn1 >= 'a') {
            n1 = 26 + cn1 - 'a';
        } else {
            n1 = cn1 - 'A';
        }

        if (cn2 >= 'a') {
            n2 = 26 + cn2 - 'a';
        } else {
            n2 = cn2 - 'A';
        }

        auto e1 = new Edge();
        auto e2 = new Edge();

        e1 -> f = e2 -> f = 0;
        e1 -> to = n2;
        e2 -> to = n1;
        e1 -> c = e2 -> c = c;
        e1 -> reverse = e2;
        e2 -> reverse = e1;

        adj[n1].push_back(e1);
        adj[n2].push_back(e2);
    }

    while (true) {
        vector<Edge*> prev(52, nullptr);
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            for (auto e: adj[f]) {
                if (e -> residual() <= 0) {
                    continue;
                }

                if (prev[e -> to]) {
                    continue;
                }

                q.push(e -> to);
                prev[e -> to] = e;

                if (prev['Z' - 'A']) {
                    break;
                }
            }
            if (prev['Z' - 'A']) {
                break;
            }
        }

        if (prev['Z' - 'A']) {
            int F = 987654321;

            int cur = 'Z' - 'A';
            while (cur != 'A' - 'A') {
                auto prev_ = prev[cur];
                F = min(F, prev_ -> residual());
                cur = prev_ -> reverse -> to;
            }

            cur = 'Z' - 'A';
            while (cur != 'A' - 'A') {
                auto prev_ = prev[cur];
                prev_ -> f += F;
                prev_ -> reverse -> f -= F;
                cur = prev_ -> reverse -> to;
            }
        } else {
            break;
        }
    }

    int answer = 0;
    for (auto e: adj['Z' - 'A']) {
        answer += e -> reverse -> f;
    }

    cout << answer << '\n';
}