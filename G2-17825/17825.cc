#include <iostream>
#include <vector>

using namespace std;

const int S = 0;
const int E = 32;

vector<vector<int> > edge = {
    {10, 22, 25, 29, 30, 31, 20, 32},
    {5, 21, 24, 27, 29},
    {15, 23, 26, 28, 29},
};

vector<int> scoreFrom21To31 = {13, 22, 28, 16, 24, 27, 19, 26, 25, 30, 35};

int positionAfterMove(vector<vector<int> >& adj, int cur, int cnt) {
    if (cur == 5 || cur == 10 || cur == 15) {
        cur = adj[cur][1];
        --cnt;
    }  

    while (cnt-- && cur != E) {
        cur = adj[cur][0];     
    }

    return cur;
}

bool horseExists(vector<int>& horse, int p) {
    if (p == E) {
        return false;
    }

    for (auto e: horse) {
        if (e == p) {
            return true;
        }
    }
    return false;
}

int answer = 0;

void f(vector<vector<int> >& adj, vector<int>& dice, vector<int>& score, vector<int>& horse, int idx, int scoreSum) {
    if (idx == 10) {
        answer = max(answer, scoreSum);
        return;
    }

    for (int i = 0; i < horse.size(); ++i) {
        if (horse[i] == E) {
            continue;
        }

        int before = horse[i];
        int after = positionAfterMove(adj, before, dice[idx]);

        if (horseExists(horse, after)) {
            continue;
        }
        horse[i] = after;
        f(adj, dice, score, horse, idx + 1, scoreSum + score[after]);
        horse[i] = before;
    }
}

int main() {
    vector<vector<int> > adj(E + 1);
    vector<int> score(E + 1, 0);
    vector<int> dice(10);

    for(auto& e: dice) {
        cin >> e;
    }

    for (int i = 0; i < 20; ++i) {
        adj[i].push_back(i + 1);
        score[i] = 2 * i;
    }
    score[20] = 40;

    for (auto v: edge) {
        for (int i = 0; i < v.size() - 1; ++i) {
            adj[v[i]].push_back(v[i + 1]);
        }
    }

    for (int i = 21; i <= 31; ++i) {
        score[i] = scoreFrom21To31[i - 21];
    }

    vector<int> horse = {0, 0, 0, 0};
    f(adj, dice, score, horse, 0, 0);

    cout << answer << '\n';          
}