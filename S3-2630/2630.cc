#include <iostream>

using namespace std;

#define N_MAX 128

int arr[N_MAX][N_MAX] = {0};
int N;

int answer[2] = {0};

void f(int r, int c, int width) {

    int first = arr[r][c];

    bool isOneColor = true;
    for (int i = r; i < r + width; i++) {

        if (!isOneColor) {
            break;
        }
        
        for (int j = c; j < c + width; j++) {
            if (arr[i][j] != first) {
                isOneColor = false;
                break;
            }
        }
    }

    if (isOneColor) {
        answer[first]++;
    } else {
        int half = width / 2;

        f(r, c, half);
        f(r, c + half, half);
        f(r + half, c, half);
        f(r + half, c + half, half);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    f(0, 0, N);

    cout << answer[0] << "\n" << answer[1] << "\n";

}