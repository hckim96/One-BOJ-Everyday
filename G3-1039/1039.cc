#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    string N;
    int K;
    cin >> N >> K;

    queue<string> q;
    set<string> visited;
    q.push(N);
    int changedCnt = 1;
    int answer = -1;
    
    while (!q.empty() && changedCnt <= K) {
        int levelSize = q.size();
        while (levelSize--) {
            auto ss = q.front();
            q.pop();
            for (int i = 0; i < ss.size(); ++i) {
                for (int j = i + 1; j < ss.size(); ++j) {
                    string ns(ss);
                    swap(ns[i], ns[j]);

                    if (ns[0] == '0') {
                        continue;
                    }
                    if (visited.find(ns) != visited.end()) {
                        continue;
                    }

                    visited.insert(ns);
                    q.push(ns);
                    if (changedCnt == K) {
                        answer = max(answer, stoi(ns));
                    }
                }
            }
        }
        visited.clear();
        ++changedCnt;
    }
    
    cout << answer << '\n';    
}
