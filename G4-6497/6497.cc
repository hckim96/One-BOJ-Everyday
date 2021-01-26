#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define N_MAX 200000

int M, N, X, Y, Z;
vector<int> parent(N_MAX, -1);

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
    cin.tie(nullptr);

    while (true) {
        cin >> M >> N;

        if (M == 0 && N == 0) {
            break;
        }

        fill(parent.begin(), parent.end(), -1);
        
        int totalCost = 0;
        vector<tuple<int, int, int> > edge;

        while (N--) {
            cin >> X >> Y >> Z;
            totalCost += Z;
            edge.push_back({Z, X, Y});
        }

        sort(edge.begin(), edge.end());

        int mstCost = 0;
        for (auto & e: edge) {
            auto [z, x, y] = e;

            if (myFind(x) != myFind(y)) {
                mstCost += z;
                myUnion(x, y);
            }
        }

        cout << totalCost - mstCost << "\n";
    }
}