#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    int Tlen = T.size();
    int Plen = P.size();

    if (Plen > Tlen) {
        cout << "0\n";
        return 0;
    }

    vector<int> pi(Plen, 0);

    int j = 0;
    for (int i = 1; i < Plen; ++i) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }
        if (P[i] == P[j]) {
            ++j;
            pi[i] = j;
        }
    }

    vector<int> answer;
    j = 0;

    for (int i = 0; i < Tlen; ++i) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }
        if (T[i] == P[j]) {
            if (j == Plen - 1) {
                answer.push_back(i - Plen + 2);
                j = pi[j];
            } else {
                ++j;
            }
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
