#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int N;
        cin >> N;

        string s;
        cin >> s;

        int DCnt = 0;
        for (auto e: p) {
            if (e == 'D') {
                ++DCnt;
            }
        }
        
        if (DCnt > N) {
            cout << "error\n";
            continue;
        }

        if (N == 0) {
            cout << "[]\n";
            continue;
        }

        vector<int> arr(N, 0);

        int idx = 0;
        for (int i = 1; i < s.size(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                arr[idx] *= 10;
                arr[idx] += s[i] - '0';
            } else {
                ++idx;
            }
        }

        int left = 0;
        int right = N - 1;
        bool reversed = false;
        for (auto e: p) {
            if (e == 'R') {
                reversed = !reversed;
            } else {
                if (reversed) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        string answer;
        answer += '[';
        if (!reversed) {
            for (int i = left; i <= right; ++i) {
                answer += to_string(arr[i]);
                if (i != right) {
                    answer += ',';
                }
            }
        } else {
            for (int i = right; i >= left; --i) {
                answer += to_string(arr[i]);
                if (i != left) {
                    answer += ',';
                }
            }
        }
        answer += "]\n";

        cout << answer;
    }
}
