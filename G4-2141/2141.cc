#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<pair<long long, long long> > v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));
    for (int i = 0; i < N; ++i) {
        if (i) v[i].second += v[i - 1].second;
    }
    long long sum = v[N - 1].second;
    
    for (int i = 0; i < N; ++i) {
        if (v[i].second >= sum + 1 >> 1) {
            cout << v[i].first << '\n';
            break;
        }
    }
}