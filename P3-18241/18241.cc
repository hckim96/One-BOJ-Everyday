#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string w, tmp;
    cin >> w >> tmp;

    int N;
    cin >> N;

    deque<char> dqL, dqR, s(tmp.begin(), tmp.end());

    auto R = [&]() {
        while (!s.empty()) {
            dqR.push_front(s.back());
            s.pop_back();
            if (dqR.size() >= w.size() && dqR.front() == w.front()) {
                bool matched = true;
                for (int i = 1; i < w.size(); ++i) {
                    if(dqR[i] != w[i]) {
                        matched = false;
                        break;
                    }
                }
                if (matched) {
                    int tmp = w.size();
                    while (tmp--) dqR.pop_front();
                    return true;
                }
            }
        }
        return false;
    };
    auto L = [&]() {
        while (!s.empty()) {
            dqL.push_back(s.front());
            s.pop_front();
            if (dqL.size() >= w.size() && dqL.back() == w.back()) {
                bool matched = true;
                for (int i = 0; i < w.size() - 1; ++i) {
                    if(dqL[dqL.size() - w.size() + i] != w[i]) {
                        matched = false;
                        break;
                    }
                }
                if (matched) {
                    int tmp = w.size();
                    while (tmp--) dqL.pop_back();
                    return true;
                }
            }
        }
        return false;
    };
    auto LR = [&]() {
        while (dqL.size()) {
            dqR.push_front(dqL.back());
            dqL.pop_back();
            if (dqR.size() >= w.size() && dqR.front() == w.front()) {
                bool matched = true;
                for (int i = 1; i < w.size(); ++i) {
                    if(dqR[i] != w[i]) {
                        matched = false;
                        break;
                    }
                }
                if (matched) {
                    int tmp = w.size();
                    while (tmp--) dqR.pop_front();
                    return true;
                }
            }
        }
        return false;
    };

    int successCnt = 0;
    while (N--) {
        char op; cin >> op;
        if (op == 'L') successCnt += L() || LR();
        else successCnt += R() || LR();
    }

    cout << successCnt << '\n';

    for (auto e: dqL) cout << e;
    for (auto e: s) cout << e;
    for (auto e: dqR) cout << e;
    cout << '\n';

    if (L() || R() || LR()) {
        cout << "You Lose!\n";
    } else {
        cout << "Perfect!\n";
    }
}