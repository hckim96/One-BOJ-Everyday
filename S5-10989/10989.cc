#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> cnt(10001, 0);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        
        ++cnt[num];
    }

    for (int i = 1; i <= 10000; ++i) {
        while (cnt[i]--) {
            cout << i << '\n';
        }
    }
}
