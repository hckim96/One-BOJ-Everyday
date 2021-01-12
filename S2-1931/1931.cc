#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100000

int N;
pair<int, int> conference[N_MAX];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        conference[i] = {a, b};
    }

    sort(&conference[0], &conference[0] + N, cmp);

    int last = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (last <= conference[i].first) {
            cnt++;
            last = conference[i].second;
        }
    }
    cout << cnt << "\n";
}