#include <iostream>

using namespace std;

#define N_MAX 1000000

int parent[N_MAX + 1] = {0};

int N, M;

int myFind(int a) {
    if (parent[a] == -1) {
        return a;
    } else {
        return parent[a] = myFind(parent[a]);
    }
}

void myUnion(int a, int b) {
    int parent1, parent2;
    parent1 = myFind(a);
    parent2 = myFind(b);

    if (parent1 == parent2) {
        return;
    }
    parent[parent1] = parent2;
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    fill_n(parent, N + 1, -1);

    int mode, a, b;
    for (int i = 0; i < M; i++) {
        cin >> mode >> a >> b;

        if (mode == 0) {
            myUnion(a, b);
        } else {
            if (myFind(a) == myFind(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}