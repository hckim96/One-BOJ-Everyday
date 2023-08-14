#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> tl;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

int N, K;


vi cost(100001, 1e9);
void bfs() {
    queue<int> q;
    q.push(N);
    cost[N] = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (i != 0) {
            int j = i;
            while (2 * j <= 100000) {
                if (cost[2 * j] > cost[j]) {
                    cost[2 * j] = min(cost[j], cost[2 * j]);
                    q.push(2 * j);
                }
                j = j * 2;
            }
        }

        if (i + 1 <= 100000 && cost[i + 1] > cost[i] + 1) {
            cost[i + 1] = min(cost[i] + 1, cost[i + 1]);
            q.push(i + 1);
        }

        if (i - 1 >= 0 && cost[i - 1] > cost[i] + 1) {
            cost[i - 1] = min(cost[i] + 1, cost[i - 1]);
            q.push(i - 1);
        }

        // if (cost[K] != 1e9) {
        //     break;
        // }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #if !defined(ONLINE_JUDGE)
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> K;

    bfs();

    cout << cost[K] << "\n";
}

