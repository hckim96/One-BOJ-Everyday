#include <iostream>

using namespace std;

int N, P, T;
bool canTroll = false;
int main() {
    cin >> N >> P >> T;

    int pos, cnt, add;
    cnt = 1;
    add = 1;
    pos = -1;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < cnt; j++) {
            pos = (pos + 1) % (2 * N);
            if (i == T - 1 && (pos == 2 * (P - 1) || pos == 2 * (P - 1) + 1)) {
                canTroll = true;
                break;
            }
        }

        if (cnt == 2 * N) {
            add = -1;
        } 

        if (cnt == 1) {
            add = 1;
        }
        cnt += add;
    }

    if (canTroll) {
        cout << "Dehet YeonJwaJe ^~^\n";
    } else {
        cout << "Hing...NoJam\n";
    }
}
