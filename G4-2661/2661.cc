#include <iostream>

using namespace std;

#define N_MAX 80

int N;
char sequence[N_MAX + 1]; 

bool gotAnswer = false;

bool isGoodSequence(int len) {
    if (gotAnswer) {
        return false;
    }

    int sublen = 2;

    for (; sublen < len / 2 + 1; sublen++) {
        for (int i = len - 2 * sublen; i + 2 * sublen <= len; i++) {
            bool flag = true;
            for (int j = 0; j < sublen; j++) {
                if (sequence[i + j] != sequence[i + sublen + j]) {
                    flag = false;
                }
            }

            if (flag) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int len) {
    if (len == N) {
        if (gotAnswer) {
            return;
        }
        gotAnswer = true;
        sequence[len] = '\0';
        cout << sequence << '\n';
        return;
    }

    if (gotAnswer) {
        return;
    }
    
    for (int i = 49; i < 52; i++) {
        if (len == 0) {
            sequence[len] = char(i);
            dfs(len + 1);
        } else if (sequence[len - 1] != char(i)) {
            sequence[len] = char(i);
            if (isGoodSequence(len + 1)) {
                dfs(len + 1);
            }
        } 
    }
}

int main() {
    cin >> N;

    dfs(0);
}