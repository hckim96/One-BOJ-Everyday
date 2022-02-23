#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    
    vector<int> a(360000), b(360000);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        a[num] = 1;
    }
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        b[num] = 1;
    }

    auto buildPi = [&](vector<int>& p) {
        int pLen = p.size();
        vector<int> pi(pLen, 0);
        for (int j = 0, i = 1; i < pLen; ++i) {
            while (j > 0 && p[i] != p[j]) j = pi[j - 1];
            if (p[i] == p[j]) ++j, pi[i] = j;
        }
        return pi;
    };
    auto kmp = [&](vector<int>& s, vector<int>& p) {
        // find p in s
        vector<int> answer;
        int sLen = s.size(), pLen = p.size();
        auto pi = buildPi(p);
        for (int j = 0, i = 0; i < 2 * sLen; ++i) {
            while (j > 0 && s[i % sLen] != p[j]) j = pi[j - 1];
            if (j == pLen - 1) answer.push_back(i % sLen - pLen + 2), j = pi[j];
            else ++j;
        }
        return answer;
    };

    auto answer = kmp(a, b);
    if (answer.size()) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }
}