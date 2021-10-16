#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        string X, Y, W;
        cin >> X >> Y >> W;

        vector<vector<int> > sumX(X.size(), vector<int> (26, 0));
        vector<vector<int> > sumY(Y.size(), vector<int> (26, 0));

        for (int i = 0; i < X.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i) {
                    sumX[i][j] = sumX[i - 1][j] + (X[i] - 'a' == j);
                } else {
                    sumX[i][j] = X[i] - 'a' == j;
                }
            }
        }
        for (int i = 0; i < Y.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i) {
                    sumY[i][j] = sumY[i - 1][j] + (Y[i] - 'a' == j);
                } else {
                    sumY[i][j] = Y[i] - 'a' == j;
                }
            }
        }
        vector<int> lx(W.size());
        vector<int> rx(W.size());

        int is = 0;
        int iw = 0;

        while (iw < W.size()) {
            if (X[is] == W[iw]) {
                lx[iw] = is;
                ++iw;
            }
            ++is;
        }

        is = X.size() - 1;
        iw = W.size() - 1;

        while (iw >= 0) {
            if (X[is] == W[iw]) {
                rx[iw] = is;
                --iw;
            }
            --is;
        }

        //

        vector<int> ly(W.size());
        vector<int> ry(W.size());

        is = 0;
        iw = 0;

        while (iw < W.size()) {
            if (Y[is] == W[iw]) {
                ly[iw] = is;
                ++iw;
            }
            ++is;
        }

        is = Y.size() - 1;
        iw = W.size() - 1;

        while (iw >= 0) {
            if (Y[is] == W[iw]) {
                ry[iw] = is;
                --iw;
            }
            --is;
        }

        bool answer = false;
        for (int i = 0; i < W.size() + 1; ++i) {
            int rxidx;
            int lxidx;
            int ryidx;
            int lyidx;
            if (i == 0) {
                rxidx = rx[i] - 1;
                lxidx = -1;
                ryidx = ry[i] - 1;
                lyidx = -1;
            } else if (i == W.size()) {
                rxidx = X.size() - 1;
                lxidx = lx[i - 1];
                ryidx = Y.size() - 1;
                lyidx = ly[i - 1];
            } else {
                rxidx = rx[i] - 1;
                lxidx = lx[i - 1];
                ryidx = ry[i] - 1;
                lyidx = ly[i - 1];
            }

            for (int j = 0; j < 26; ++j) {
                int tmpX = 0;
                int tmpY = 0;

                if (rxidx != -1) tmpX += sumX[rxidx][j];
                if (lxidx != -1) tmpX -= sumX[lxidx][j];
                if (ryidx != -1) tmpY += sumY[ryidx][j];
                if (lyidx != -1) tmpY -= sumY[lyidx][j];
                
                if (tmpX && tmpY) {
                    answer = true;
                    break;
                }
            }
            if (answer) {
                break;
            }
        }
        cout << answer << '\n';
    }
}