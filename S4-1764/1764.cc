#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
vector<string> answer;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N + M - 1; i++) {
        if (v[i] == v[i + 1]) {
            answer.push_back(v[i]);
            i++;
        }
    }

    cout << answer.size() << "\n";
    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << "\n";
    }
}