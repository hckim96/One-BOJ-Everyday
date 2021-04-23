#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    }

    return parent[n] = myFind(parent[n]);
}

void myUnion(int n1, int n2) {
    int p1 = myFind(n1);
    int p2 = myFind(n2);

    if (p1 != p2) {
        parent[p1] = p2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    parent.resize(N);
    fill(parent.begin(), parent.end(), -1);

    for (int i = 1; i <= M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;

        if (myFind(n1) == myFind(n2)) {
            cout << i << '\n';
            return 0;
        }

        myUnion(n1, n2);
    }

    cout << "0\n";
}
