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
    for (auto& e: v) cin >> e.first >> e.second;

    
    int s, e;
    cin >> s >> e;

    bool reverse_ = false;
    
    if (s > e) {
        reverse_ = true;
        swap(s, e);
    }
    
    if (!s) {
        reverse_ = !reverse_;
        s = e;
        e = N;
        v.push_back(v[0]);
    }
    auto ccw = [&](pair<long long, long long>& p1, pair<long long, long long>& p2, pair<long long, long long>& p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first) >= 0LL;
    };

    auto find = [&](int ss, int ee) {
        int j = ss + 1;
        while (j != ee && ccw(v[ss], v[j], v[ee])) {
            ++j;
        }
        return j;
    };

    vector<int> answer;
    
    // int cur = s;
    // while (cur != e) {
    //     answer.push_back(cur);
    //     cur = find(cur, e);
    // }
    // answer.push_back(cur);

    answer.push_back(s);
    for (int i = s + 1; i <= e; ++i) {
        while (answer.size() >= 2 && ccw(v[answer[answer.size() - 2]], v[answer[answer.size() - 1]], v[i])) answer.pop_back();
        answer.push_back(i);
    }

    cout << answer.size() << '\n';
    if (reverse_) reverse(all(answer));
    for (auto e: answer) cout << e % N << ' ';
    cout << '\n';
}