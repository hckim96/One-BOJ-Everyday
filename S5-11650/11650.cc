#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100000

int N;
pair<int, int> coord[N_MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coord[i] = {x, y};
    }

    sort(coord, coord + N, less<pair<int, int> >());

    for (int i = 0; i < N; i++) {
        cout << coord[i].first << " " << coord[i].second << "\n";
    }
}