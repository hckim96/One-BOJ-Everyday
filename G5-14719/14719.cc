#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W;
    cin >> H >> W;

    vector<int> h(W, 0);
    vector<int> v(W, INF);

    int tmp = -INF;
    for (int i = 0; i < W; ++i) {
        cin >> h[i];
        v[i] = min(v[i], tmp);
        tmp = max(tmp, h[i]);
    }

    tmp = -INF;
    for (int i = W - 1; i >= 0; --i) {
        v[i] = min(v[i], tmp);
        tmp = max(tmp, h[i]);
    }

    int answer = 0;
    for (int i = 0; i < W; ++i) {
        answer += (v[i] - h[i] > 0 ? v[i] - h[i] : 0);
    }

    cout << answer << '\n';
}