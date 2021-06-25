#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    long long B;

    cin >> N >> M >> B;

    vector<int> height(257, 0);

    int minH = 256;
    int maxH = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;
            minH = min(minH, num);
            maxH = max(maxH, num);
            ++height[num];
        }
    }

    int answerH = 0;
    long long answerS = 256 * 500 * 500 * 2;

    for (int h = minH; h <= maxH; ++h) {
        long long del = 0;
        long long put = 0;

        for (int hh = 0; hh < h; ++hh) {
            put += (h - hh) * height[hh];
        }
        for (int hh = h + 1; hh <= maxH; ++hh) {
            del += (hh - h) * height[hh];
        }

        if (B + del - put < 0) {
            continue;
        }

        long long s = del * 2 + put;

        if (s < answerS) {
            answerH = h;
            answerS = s;
        } else if (s == answerS) {
            if (h > answerH) {
                answerH = h;
                answerS = s;
            }
        }
    }

    cout << answerS << ' ' << answerH << '\n';
}
