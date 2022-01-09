#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (auto& e: a) {
        cin >> e;
    }
    sort(all(a));
    cout << a[K - 1] << '\n';
}