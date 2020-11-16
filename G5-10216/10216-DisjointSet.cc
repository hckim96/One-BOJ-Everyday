#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;

#define N_MAX 3000
int T, N;

int parent[N_MAX] = {0};
vector<tuple<double, double, double> > camp;

int myFind(int node) {
    if (parent[node] == -1) {
        return node;
    } else {
        return parent[node] = myFind(parent[node]);
    }
}

void myUnion(int node1, int node2) {
    parent[myFind(node2)] = node1;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        fill_n(parent, N_MAX, -1);
        
        cin >> N;
        int cnt = N;

        camp.reserve(N * sizeof(tuple<double, double, double>));

        for (int j = 0; j < N; j++) {
            int r, c, R;
            cin >> c >> r >> R;
            camp.push_back({r, c, R});
        }

        for (int k = 0; k < N; k++) {
            for (int l = k + 1; l < N; l++) {
                double r1, c1, R1, r2, c2, R2;
                tie(r1, c1, R1) = camp[k];
                tie(r2, c2, R2) = camp[l];
                double distance = sqrt(pow(r1 - r2, 2) + pow(c1 - c2, 2));
                double sumOfRange = R1 + R2;

                if (sumOfRange >= distance) {
                    if (myFind(k) != myFind(l)) {
                        myUnion(k, l);
                        cnt--;
                    }
                }
            }
        }

        cout << cnt << "\n";       
        camp.clear();
        vector<tuple<double, double, double> > ().swap(camp);
    }
}