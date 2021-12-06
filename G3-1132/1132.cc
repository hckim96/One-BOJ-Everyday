#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);


    vector<pair<long long, long long> > cnt(10);
    for (int i = 0; i < 10; ++i) {
        cnt[i] = {0, i};
    }
    vector<int> canBeZero(10, true);
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        long long tmp = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            cnt[s[i] - 'A'].first += tmp;
            tmp *= 10;
            if (i == 0) {
                canBeZero[s[i] - 'A'] = false;
            }
        }
    }

    sort(all(cnt));
    for (int i = 0; i < 10; ++i) {
        if (canBeZero[cnt[i].second]) {
            cnt.erase(cnt.begin() + i);
            break;
        }
    }

    long long mul = 9;
    long long answer = 0;
    for (int i = cnt.size() - 1; i >= 0; --i) {
        answer += mul * cnt[i].first;
        --mul;
    }

    cout << answer << '\n';
}