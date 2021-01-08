#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N_MAX 50

int bit[N_MAX] = {0};

int base[5] = {'a', 'c', 'i', 't', 'n'};
int candidateNum = 0;
vector<char> candidate;
int selected = 532741; // 'a' 'c' 'i' 't' 'n'

int N, K;

int answer = -1;
void dfs(int idx, int cnt) {

    if (cnt == K) {
        int canRead = 0;
        // check
        for (int i = 0; i < N; i++) {
            if ((bit[i] & selected) == bit[i]) {
                canRead++;
            }
        }
        answer = max(answer, canRead);
        return;
    }
    
    if (idx >= candidateNum) {
        return;
    }

    int tmp = 1 << (candidate[idx] - 'a');

    dfs(idx + 1, cnt);
    selected += tmp;
    dfs(idx + 1, cnt + 1);
    selected -= tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    if (K < 5) {
        while (N--) {
            string tmp;
            cin >> tmp;
        }
        cout << "0\n";
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 4; j < tmp.size() - 4; j++) {
            bit[i] |= 1 << (tmp[j] - 'a');
            candidate.push_back(tmp[j]);
        }
    }

    sort(candidate.begin(), candidate.end());
    candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());
    for (auto c : base) {
        auto it = find(candidate.begin(), candidate.end(), c);
        if (it != candidate.end()) {
            candidate.erase(it);
        }
    }
    candidateNum = candidate.size();

    if (candidateNum + 5 <= K) {
        cout << N << "\n";
        return 0;
    }

    dfs(0, 5);

    cout << answer << "\n";
}