#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 1000

int num[N_MAX] = {0};
int len[N_MAX] = {0};
vector<int> subsequence[N_MAX];
vector<int> answer;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        subsequence[i].push_back(num[i]);
        len[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (len[j] + 1 > len[i] && num[j] < num[i]) {
                len[i] = len[j] + 1;
                subsequence[i] = subsequence[j];
                subsequence[i].push_back(num[i]);
            }
        }

        if (answer.size() < subsequence[i].size()) {
            answer = subsequence[i];
        }
    }

    cout << answer.size() << "\n";
    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}