#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

struct Trie {
    bool isTerminal;
    Trie* children[26];
    vector<int> idxList;
    Trie() {
        isTerminal = false;
        fill_n(children, 26, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i]) delete children[i];
        }
    }
};

void insert(Trie* root, string key) {
    Trie* tmp = root;
    for (auto e: key) {
        int idx = e - 'a';
        if (!tmp -> children[idx]) {
            tmp -> children[idx] = new Trie();
            tmp -> idxList.push_back(idx);
        }
        tmp = tmp -> children[idx];
    }
    tmp -> isTerminal = true;
}

bool search(Trie* root, string key) {
    Trie* tmp = root;
    for (auto e: key) {
        int idx = e - 'a';
        if (!tmp -> children[idx]) {
            return false;
        }
        tmp = tmp -> children[idx];
    }
    return tmp -> isTerminal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    while (cin >> N) {
        Trie* root = new Trie();
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            insert(root, s);
        }

        long double answer = 0;
        function<void(Trie*, int)> f = [&](Trie* cur, int cnt) {
            if (cur -> isTerminal) {
                answer += cnt;
            }
            if (cur == root) ++cnt;
            if (cur != root && cur -> isTerminal && cur -> idxList.size()) ++cnt;
            if (cur != root && !cur -> isTerminal && cur -> idxList.size() >= 2) ++cnt;

            for (auto idx: cur -> idxList) {
                f(cur -> children[idx], cnt);
            }
        };
        f(root, 0);
        cout.precision(2);
        cout << fixed << answer / N << '\n';
        delete root;
    }
}