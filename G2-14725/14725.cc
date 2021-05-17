#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct Node {
    map<string, Node*> children;
} Node;

void insert(Node& root, vector<string>& seq) {
    Node* cur = &root;
    for (auto s: seq) {
        auto it = cur -> children.find(s);
        if (it == cur -> children.end()) {
            Node* newNode = new Node();
            cur -> children.insert({s, newNode});
        }
        cur = cur -> children[s];
    }
}

void print(Node& root, int depth) {
    for (auto & e: root.children) {
        for (int i = 0; i < depth; ++i) {
            cout << "--";
        }
        cout << e.first << '\n';
        print(*e.second, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Node root;
    
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        vector<string> seq(num);
        for (auto & e: seq) {
            cin >> e;
        }
        insert(root, seq);
    }
    print(root, 0);
}
