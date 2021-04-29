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

    if (p1 == p2) {
        return;
    }
    
    parent[p2] = p1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;
    cin >> G >> P;

    parent.resize(G + 1);
    fill(parent.begin(), parent.end(), -1);

    int answer = 0;
    while (P--) {
        int g;
        cin >> g;

        int p = myFind(g);
        
        if (p) {
            ++answer;
            myUnion(p - 1, p);
        } else {
            break;
        }
    }

    cout << answer << '\n';
}
