#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;


    for (int i = 1; i <= N; ++i) {
        int j = i - 1;
        int k = N - i + 1;

        while (j--) {
            cout << ' ';
        }
        while (k--) {
            cout << '*';
        }
        cout << '\n';
    }
}