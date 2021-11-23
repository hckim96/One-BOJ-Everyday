#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct Trie {
    Trie* child[2] = {NULL, NULL};
    bool isTerminal = false;

    void insert(long long key) {
        auto p = 64 - __builtin_clzll(key);
        auto cur = this;
        while (--p >= 0) {
            bool tmp = key & (1LL << p);
            if (cur -> child[tmp] == NULL) cur -> child[tmp] = new Trie();
            cur = cur -> child[tmp];
        }
        cur -> isTerminal = true;
    }
};

auto root = new Trie();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        root -> insert(x);
    }

    long long answer = 0;
    function<int(Trie*)> f = [&](Trie* cur) {
        int ret = 0;
        ret += cur -> isTerminal;

        for (auto e: cur -> child) {
            if (e != NULL) ret += f(e);
        }
        if (ret && ret != N) ++answer;
        return ret;
    };

    f(root);
    cout << answer + 1 << '\n';
}