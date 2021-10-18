#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
vector<long long> team;
vector<long long> sub;
vector<long long> maxExclude;

void f(vector<vector<int> >& children, vector<int>& s, int cur) {
    team[cur] = sub[cur] = s[cur];
    maxExclude[cur] = -INF;

    for (auto c: children[cur]) {
        f(children, s, c);

        sub[cur] = max(sub[cur], sub[c]);
        if (team[c] > 0) {
            team[cur] += team[c];
            maxExclude[cur] = max(maxExclude[cur], maxExclude[c]);
        } else {
            maxExclude[cur] = max(maxExclude[cur], sub[c]);
        }
    }

    sub[cur] = max(sub[cur], team[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int> > children(N + 1);
    vector<int> s(N + 1);
    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> s[i] >> p;

        if (p != -1) children[p].push_back(i); 
    }

    team.resize(N + 1);
    sub.resize(N + 1);
    maxExclude.resize(N + 1);

    f(children, s, 1);
    
    long long answer = -INF;
    for (int i = 1; i <= N; ++i) {
        answer = max(answer, team[i] + maxExclude[i]);

        if (children[i].size() < 2) continue;
        
        vector<long long> v(children[i].size());
        for (int j = 0; j < children[i].size(); ++j) {
            v[j] = sub[children[i][j]];
        }
        sort(v.begin(), v.end(), greater<long long>());

        answer = max(answer, v[0] + v[1]);
    }

    cout << answer << '\n';
}