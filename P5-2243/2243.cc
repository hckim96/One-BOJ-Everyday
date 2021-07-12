#include <iostream>
#include <vector>

using namespace std;

#define TASTENUM 1000001

vector<int> t(4 * TASTENUM, 0);

void update(int nodeNum, int nodeStart, int nodeEnd, int B, int C) {
    if (B < nodeStart || nodeEnd < B) {
        return;
    }

    t[nodeNum] += C;

    if (nodeStart == nodeEnd) {
        return;
    }
    int nodeMid = (nodeStart + nodeEnd) / 2;

    update(2 * nodeNum, nodeStart, nodeMid, B, C);
    update(2 * nodeNum + 1, nodeMid + 1, nodeEnd, B, C);

}

int query(int nodeNum, int nodeStart, int nodeEnd, int B) {
    if (nodeStart == nodeEnd) {
        return nodeStart;
    }

    int nodeMid = (nodeStart + nodeEnd) / 2;

    if (B > t[2 * nodeNum]) {
        return query(2 * nodeNum + 1, nodeMid + 1, nodeEnd, B - t[2 * nodeNum]);
    } else {
        return query(2 * nodeNum, nodeStart, nodeMid, B);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int A, B, C;

        cin >> A;
        if (A == 1) {
            cin >> B;
            int taste = query(1, 0, TASTENUM - 1, B);
            cout << taste << '\n';
            update(1, 0, TASTENUM - 1, taste, -1);
        } else {
            cin >> B >> C;
            update(1, 0, TASTENUM - 1, B, C);
        }
    }
}