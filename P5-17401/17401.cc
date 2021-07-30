#include <iostream>
#include <vector>

using namespace std;

#define MOD 1'000'000'007LL

vector<vector<int> > operator*(vector<vector<int> >& v1, vector<vector<int> >& v2) {
    vector<vector<int> > ret(v1.size(), vector<int> (v2[0].size(), 0));

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v2.size(); ++k) {
                ret[i][j] = (0LL + ret[i][j] + 1LL * v1[i][k] * v2[k][j]) % MOD;
            }
        }
    }

    return ret;
}

vector<vector<int> > oneCycle(vector<vector<vector<int> > >& adjList) {
    vector<vector<int> > ret = vector<vector<int> >(adjList[0].size(), vector<int> (adjList[0][0].size(), 0));

    for (int i = 0; i < ret.size(); ++i) {
        ret[i][i] = 1;
    }

    for (int i = 0; i < adjList.size(); ++i) {
        ret = ret * adjList[i];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, D;
    cin >> T >> N >> D;
    vector<vector<vector<int> > > adjList(T, vector<vector<int> >(N, vector<int> (N, 0)));

    for (int i = 0; i < T; ++i) {
        int M;
        cin >> M;

        while (M--) {
            int a, b, c;
            cin >> a >> b >> c;
            adjList[i][--a][--b] = c;
        }
    }

    int sqrCnt = D / T;
    int leftCnt = D % T;

    vector<vector<int> > answer(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        answer[i][i] = 1;
    }

    if (sqrCnt) {
        auto _oneCycle = oneCycle(adjList);
        while (sqrCnt) {
            if (sqrCnt & 1) {
                answer = answer * _oneCycle;
            }
            _oneCycle = _oneCycle * _oneCycle;
            sqrCnt >>= 1;
        }
    }

    for (int i = 0; i < leftCnt; ++i) {
        answer = answer * adjList[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}