#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 50

vector<int> parent(N_MAX + 1, -1);

int N, M;
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
        parent[p2] = p1;
    }
}

int main() {
    cin >> N >> M;

    int knowNum;
    cin >> knowNum;
    int knowFirst = 0;
    if (knowNum > 0) {
        cin >> knowFirst;
        for (int i = 1; i < knowNum; i++) {
            int tmp;
            cin >> tmp;
            myUnion(knowFirst, tmp);
        }
    }

    vector<int> personOfParty;

    for (int i = 0; i < M; i++) {
        int peopleNum;
        cin >> peopleNum;

        if (peopleNum > 0) {
            int first;
            cin >> first;
            personOfParty.push_back(first);
            for (int j = 1; j < peopleNum; j++) {
                int tmp;
                cin >> tmp;
                myUnion(first, tmp);
            }
        }
    }

    int answer = 0;

    for (auto p: personOfParty) {
        if (myFind(knowFirst) != myFind(p)) {
            answer++;
        }
    }
    
    cout << answer << '\n';
}