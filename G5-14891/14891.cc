#include <iostream>
#include <vector>

using namespace std;

void rotate(string& s, int dir) {
    if (dir == 1) {
        s = s[s.size() - 1] + s;
        s= s.substr(0, 8);
    } else {
        s = s + s[0];
        s = s.substr(1, 8);
    }
}

void f(vector<string>& arr, int idx, int dir) {
    vector<bool> same(3, 0);

    for (int i = 0; i < 3; ++i) {
        same[i] = !((arr[i][2] - '0') ^ (arr[i + 1][6] - '0'));
    }

    rotate(arr[idx], dir);
    int tmp = -dir;
    for (int i = idx - 1; i >= 0; --i) {

        if (same[i]) {
            break;
        }
        rotate(arr[i], tmp);
        tmp *= -1;
    }

    tmp = -dir;
    for (int i = idx + 1; i <= 3; ++i) {
        if (same[i - 1]) {
            break;
        }
        rotate(arr[i], tmp);
        tmp *= -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arr(4);

    for (auto &e: arr) {
        cin >> e;
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int idx, dir;
        cin >> idx >> dir;

        --idx;

        f(arr, idx, dir);
    }

    int answer = 0;
    for (int i = 0; i < 4; ++i) {
        answer += ((arr[i][0] - '0') << i);
    }
    cout << answer << '\n';
}