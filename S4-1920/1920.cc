#include <iostream>
#include <unordered_map>

using namespace std;

#define M_MAX 100000

unordered_map<int, int> um;

int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        um[tmp] = 1;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        if (um.find(tmp) != um.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}