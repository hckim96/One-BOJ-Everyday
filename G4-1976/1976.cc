#include <iostream>

using namespace std;

#define N_MAX 200

int N, M;
int parent[N_MAX + 1] = {0};

int myFind(int a) {
    if (parent[a] == 0) {
        return a;
    }

    return parent[a] = myFind(parent[a]);
}

void myUnion(int a, int b) {
    int p1, p2;
    p1 = myFind(a);
    p2 = myFind(b);

    if (p1 != p2) {
        parent[p1] = p2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (i < j && num == 1) {
                myUnion(i + 1, j + 1);
            }
        }
    }

    bool isYes = true;
    int num;
    cin >> num;
    int parent = myFind(num);

    for (int i = 1; i < M; i++) {
        cin >> num;
        if (parent != myFind(num)) {
            isYes = false;
            break;
        }
    }

    if (isYes) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}