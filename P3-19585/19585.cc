#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

struct Trie {
    bool isTerminal;
    map<char, Trie*> children;
    Trie() {
        isTerminal = false;
    }

    ~Trie() {
        for (auto& e: children) {
            delete e.second;
        }
        children.clear();
    }
};

void insert(Trie* root, string key) {
    Trie* tmp = root;
    for (auto e: key) {
        if (tmp -> children.find(e) == tmp -> children.end()) {
            tmp -> children[e] = new Trie();
        }
        tmp = tmp -> children[e];
    }
    tmp -> isTerminal = true;
}
void insert_rev(Trie* root, string key) {
    Trie* tmp = root;
    for (int i = key.size() - 1; i >= 0; --i) {
        if (tmp -> children.find(key[i]) == tmp -> children.end()) {
            tmp -> children[key[i]] = new Trie();
        }
        tmp = tmp -> children[key[i]];
    }
    tmp -> isTerminal = true;
}

void check(Trie* root, vector<int>& checked, string& key) {
    auto cur = root;
    for (int i = 0; i < key.size(); ++i) {
        if (cur -> children.find(key[i]) == cur -> children.end()) return;
        cur = cur -> children[key[i]];        
        if (cur -> isTerminal) checked[i] = true;
    }
}
void check_rev(Trie* root, vector<int>& checked, string& key) {
    auto cur = root;
    for (int i = key.size() - 1; i >= 0; --i) {
        if (cur -> children.find(key[i]) == cur -> children.end()) return;
        cur = cur -> children[key[i]];
        if (cur -> isTerminal) checked[i] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, C, Q;
    cin >> C >> N;

    Trie* color = new Trie();
    Trie* name = new Trie();
    for (int i = 0; i < C; ++i) {
        string s;
        cin >> s;
        insert(color, s);
    }
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        insert_rev(name, s);
    }

    cin >> Q;
    while (Q--) {
        string ss;
        cin >> ss;
        vector<int> checked1(ss.size(), 0);
        vector<int> checked2(ss.size(), 0);
        check(color, checked1, ss);
        check_rev(name, checked2, ss);
        bool yes = false;
        for (int i = 0; i < ss.size() - 1; ++i) {
            if (checked1[i] == 1 && checked2[i + 1] == 1) {
                yes = true;
                break;
            }
        }
        if (yes) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}