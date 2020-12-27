#include <iostream>

using namespace std;

int T, H, W, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;

    while (T--) {
        cin >> H >> W >> N;

        cout <<  ((N - 1) % H + 1) * 100 + ((N + H - 1) / H) << "\n";
    }
}