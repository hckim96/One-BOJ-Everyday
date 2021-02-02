#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 1000000

int N, M;
int sum[N_MAX] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<int> mod_cnt(M, 0);
    long long answer = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> sum[i];
        if (i != 0) {
            sum[i] += sum[i - 1];
        }
        sum[i] %= M;
        mod_cnt[sum[i]]++;
    }

    for (int i = 0; i < M; ++i) {
        if (mod_cnt[i] > 1) {
            answer += (long long)mod_cnt[i] * (mod_cnt[i] - 1) / 2;
        }
    }
    answer += mod_cnt[0];

    cout << answer << "\n";
}