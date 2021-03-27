#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

int f(vector<int>& seq, vector<vector<vector<int> > >& dp, int left, int right, int idx) {

    int& ret = dp[left][right][idx];

    if (idx == seq.size()) {
        return ret = 0;
    }

    if (ret != -1) {
        return ret;
    }

    int leftCost, rightCost;
    int target = seq[idx];

    // move left
    if (right == target) {
        leftCost = INF;
    } else {
        if (left == target) {
            leftCost = 1;
        } else if (left == 0) {
            leftCost = 2;
        } else if ((left + 1) % 4 + 1 == target) {
            leftCost = 4;
        } else {
            leftCost = 3;
        }
    }

    // move right
    if (left == target) {
        rightCost = INF;
    } else {
        if (right == target) {
            rightCost = 1;
        } else if (right == 0) {
            rightCost = 2;
        } else if ((right + 1) % 4 + 1 == target) {
            rightCost = 4;
        } else {
            rightCost = 3;
        }
    }

    return ret = min(leftCost + (leftCost == INF ? INF : f(seq, dp, target, right, idx + 1)), rightCost + (rightCost == INF ? INF : f(seq, dp, left, target, idx + 1)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> seq;
    int num;
    while (true) {
        cin >> num;
        if (!num) {
            break;
        }
        seq.push_back(num);
    }

    vector<vector<vector<int> > > dp(5, vector<vector<int> > (5, vector<int> (seq.size() + 1, -1)));
    cout << f(seq, dp, 0, 0, 0) << '\n';
}