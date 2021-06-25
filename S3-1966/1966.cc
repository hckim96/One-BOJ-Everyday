#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M;
        cin >> N >> M;

        int target;
        deque<pair<int, int> > dq;

        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            if (i == M) {
                target = num;
            }
            dq.push_back({num, i});
        }

        int answer = 1;
        while (!dq.empty()) {
            auto [fNum, fIdx] = dq.front();

            bool flag = true;
            for (int i = 1; i < dq.size(); ++i) {
                if (dq[i].first > fNum) {
                    dq.pop_front();
                    dq.push_back({fNum, fIdx});
                    flag = false;
                    break;
                }
            }

            if (flag) {
                if (fNum == target && fIdx == M) {
                    break;
                }
                
                dq.pop_front();
                ++answer;
            }
        }

        cout << answer << '\n';
    }
}
