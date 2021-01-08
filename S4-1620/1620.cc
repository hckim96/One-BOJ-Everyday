#include <iostream>
#include <map>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    map<string, int> m;
    map<int, string> m2;
    
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        m[tmp] = i + 1;
        m2[i + 1] = tmp;
    }

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;

        if ('0' <= tmp[0] && tmp[0] <= '9') {
            int tmpNum = stoi(tmp);
            cout << m2[tmpNum] << "\n";
        } else {
            cout << m[tmp] << "\n";
        }
    }
}