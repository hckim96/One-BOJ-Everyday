#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    long long N, L, R;
    cin >> N >> L >> R;

    if (N * 2 * R < L) {
        cout << "-1\n";
        return 0;
    }

    long long lim, maxLim, atLeast, diffSum, diffSumMin, answer;
    lim = maxLim = atLeast = diffSum = answer = 0;
    diffSumMin = 1e18;
    pair<long long, long long> p = {0, 0};

    for (int i = 1; i <= N + 1; ++i) {
        long long x;
        if (i == N + 1) {
            x = L + R;
        } else {
            cin >> x;
        }

        if (x <= lim + R) {
            lim = x + R;
        } else if (lim + R < x && x <= maxLim + R) {
            lim = x + R;
            atLeast = x - 2 * R;
        } else {
            if (p.first && maxLim + R <= p.second) {
                p.second = x;
            } else {
                if (p.first == 0) {
                    diffSum = 0;
                    answer = -(maxLim + R);
                } else {
                    diffSum += p.second - p.first;
                    diffSum -= (maxLim + R - p.second);
                }
                p = {maxLim + R, x};
                diffSumMin = min(diffSumMin, diffSum);
            }
            atLeast = x;
            lim = maxLim + 2 * R;
        }
        maxLim += 2 * R;
    }

    if (p.first == 0) {
        answer = atLeast;
    } else {
        diffSum += p.second - p.first;
        diffSum -= (atLeast - p.second);
        diffSumMin = min(diffSumMin, diffSum);

        answer += 2 * atLeast + diffSumMin;
    }
    cout << answer << '\n';
}