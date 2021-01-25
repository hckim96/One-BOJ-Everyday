#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define M_MAX 100000
int M, N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N >> L;

    vector<int> shootPlace(M , 0);
    for (int i = 0; i < M; i++) {
        cin >> shootPlace[i];
    }

    sort(shootPlace.begin(), shootPlace.end());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        int X, Y;
        int dist = 0;
        cin >> X >> Y;

        dist += Y;

        auto it = lower_bound(shootPlace.begin(), shootPlace.end(), X);
        
        if (it == shootPlace.begin()) {
            dist += *it - X;
        } else if (it == shootPlace.end()) {
            dist += X - *(it - 1);
        } else if (*it == X) {
            dist += 0;
        } else {
            dist += min(X - *(it - 1), *it - X);
        }

        if (dist <= L) {
            answer++;
        }
    }

    cout << answer << "\n";
}