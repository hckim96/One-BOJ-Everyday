#include <iostream>

using namespace std;

struct Trie {
    struct Trie* children[10];
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
        fill_n(children, 10, nullptr);
    }
    
    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (children[i]) delete children[i];
        }
	}
};

int T, N;

bool trie_insert(Trie* root, string s) {

    Trie* node = root;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        Trie* next = node -> children[s[i] - '0'];
        if (next == nullptr) {
            next = new Trie;
            node -> children[s[i] - '0'] = next;
            node = next;
            if (i == len - 1) {
                node -> isEndOfWord = true;
            }
        } else if (next -> isEndOfWord) {
            return false;
        } else {
            node = next;
        }
    }

    if (!node -> isEndOfWord) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> N;

        Trie* root = new Trie;

        bool isNO = false;
        for (int i = 0; i < N; i++) {
            string tmp;
            cin >> tmp;

            if (isNO) {
                continue;
            } else {
                if(!trie_insert(root, tmp)) {
                    isNO = true;
                }
            }
        }

        if (isNO) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

        delete root;
    }
}