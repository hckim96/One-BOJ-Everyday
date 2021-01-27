#include <iostream>
#include <vector>

using namespace std;

string order;
string bridge[2];
int orderLen, bridgeLen;

vector<vector<vector<int> > > dp(20, vector<vector<int> > (100, vector<int> (2, -1)));
int f(int orderIdx, int bridgeIdx, int curBridge) {
    if (orderIdx == orderLen) {
        return 1;
    }

    if (bridgeIdx == bridgeLen) {
        return 0;
    }

    if (dp[orderIdx][bridgeIdx][curBridge] != -1) {
        return dp[orderIdx][bridgeIdx][curBridge];
    }

    if (order[orderIdx] == bridge[curBridge][bridgeIdx]) {
        return dp[orderIdx][bridgeIdx][curBridge] = f(orderIdx, bridgeIdx + 1, curBridge) + f(orderIdx + 1, bridgeIdx + 1, !curBridge);
    } else {
        return dp[orderIdx][bridgeIdx][curBridge] = f(orderIdx, bridgeIdx + 1, curBridge);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> order >> bridge[0] >> bridge[1];

    orderLen = order.size();
    bridgeLen = bridge[0].size();

    cout << f(0, 0, 0) + f(0, 0, 1) << "\n";
}