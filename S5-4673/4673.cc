#include <iostream>
#include <vector>

using namespace std;

int nextNum(int num) {
    int ret = num;

    while (num) {
        ret += num % 10;
        num /= 10;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 10000;

    vector<bool> isSelfNum(N, true);

    for (int i = 1; i < N; ++i) {
        int tmp = nextNum(i);
        
        if (!isSelfNum[tmp]) {
            continue;
        }

        while (tmp <= N) {
            isSelfNum[tmp] = false;
            tmp = nextNum(tmp);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (isSelfNum[i]) {
            cout << i << '\n';
        }
    }
}