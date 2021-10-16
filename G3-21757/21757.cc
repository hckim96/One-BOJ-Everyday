#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> s(N, 0);
    long long zeroCnt = -1;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (i) s[i] = s[i - 1] + v[i];
        else s[i] = v[i];
        if (s[i] == 0) ++zeroCnt;
    }

    if (s[N - 1] == 0) {
        long long tmp = 1;
        for (int i = 0; i < 3; ++i) {
            tmp *= zeroCnt--;
            tmp /= i + 1;
        }
        cout << tmp << '\n';
        return 0;
    }
    int quarter = s[N - 1] / 4;


    vector<long long> vv(5, 0);
    vv[4] = 1;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 1; j <= 3; ++j) {
            if (s[i] == quarter * j) {
                vv[j] += vv[j + 1];
            } 
        }
    }
    cout << vv[1] << '\n';
}