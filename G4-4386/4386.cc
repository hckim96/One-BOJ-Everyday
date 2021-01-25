#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define N_MAX 100

int N;
double X, Y;
pair<double, double> point[N_MAX];
vector<tuple<double, int, int> > edge;
vector<int> parent(N_MAX, -1);

int myFind(int n1) {
    if (parent[n1] == -1) {
        return n1;
    }

    return parent[n1] = myFind(parent[n1]);
}

void myUnion(int n1, int n2) {
    int p1 = myFind(n1);
    int p2 = myFind(n2);

    if (p1 != p2) {
        parent[p2] = p1;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        point[i] = {X, Y};
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = sqrt(pow(point[j].first - point[i].first, 2) + pow(point[j].second - point[i].second, 2));
            edge.push_back({dist, i, j});           
        }
    }

    sort(edge.begin(), edge.end());

    double answer = 0;
    for (auto e : edge) {
        auto [dist, i, j] = e;

        if (myFind(i) != myFind(j)) {

            myUnion(i, j);
            answer += dist;
        }
    }

    cout << answer << "\n";
}