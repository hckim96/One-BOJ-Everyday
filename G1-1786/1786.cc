#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string P, T;
    getline(cin, T);
    getline(cin, P);

    int TLen = T.size();
    int PLen = P.size();

    if (PLen > TLen) {
        cout << "0\n";
        return 0;
    }

    vector<int> kmax(PLen + 1, 0);

    int cnt = 0;
    for (int i = 1; i < PLen; ++i) {
        if (P[i] == P[cnt]) {
            ++cnt;
            kmax[i + 1] = cnt;
        } else {
            cnt = 0;
        }
    }

    int i = 0;
    int j = 0;
    vector<int> answer;

    while (i < TLen) {
        if (T[i] == P[j]) {
            ++i;
            ++j;
            if (j == PLen) {
                answer.push_back(i - PLen + 1);
                i = i - (j - kmax[j]) + 1;
                j = kmax[j];
            }
        } else {
            i = i - (j - kmax[j]) + 1;
            j = kmax[j];
        }
    }

    cout << answer.size() << '\n';
    if (answer.size()) {
        for (auto e: answer) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}
