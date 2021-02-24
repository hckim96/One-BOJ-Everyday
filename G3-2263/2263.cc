#include <iostream>
#include <vector>

using namespace std;

void printPreorder(vector<int>& inorder, vector<int>& postorder, vector<int>& inorderIdx, int s1, int e1, int s2, int e2) {
    if (e1 < s1 || e2 < s2) {
        return;
    }
    
    int parent = postorder[e2];
    cout << parent << ' ';
    
    if (s1 == e1) {
        return;
    }
    
    int parentIdx = inorderIdx[parent];

    int leftSize = parentIdx - s1;

    printPreorder(inorder, postorder, inorderIdx, s1, s1 + leftSize - 1, s2, s2 + leftSize - 1);
    printPreorder(inorder, postorder, inorderIdx, s1 + leftSize + 1, e1, s2 + leftSize, e2 - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> inorder(N);
    vector<int> inorderIdx(N + 1, 0);
    vector<int> postorder(N);

    for (int i = 0; i < N; ++i) {
        cin >> inorder[i];
        inorderIdx[inorder[i]] = i;
    }

    for (auto & e: postorder) {
        cin >> e;
    }

    printPreorder(inorder, postorder, inorderIdx, 0, N - 1, 0, N - 1);
}