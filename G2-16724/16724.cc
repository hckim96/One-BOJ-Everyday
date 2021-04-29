#include <iostream>
#include <vector>
#include <map>

using namespace std;

int answer = 0;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
map<char, int> m = {{'R', 0}, {'L', 1}, {'D', 2}, {'U', 3}};

bool f(vector<vector<char> >& arr, vector<vector<int> >& visited, int r, int c, int cnt) {
    if (visited[r][c]) {
        if (visited[r][c] == cnt) {
            return true;
        } else {
            return false;
        }
    }    

    visited[r][c] = cnt;
    int dir = m[arr[r][c]];

    return f(arr, visited, r + dr[dir], c + dc[dir], cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<vector<char> > arr(N, vector<char> (M));
    vector<vector<int> > visited(N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                if(f(arr, visited, i, j, ++cnt)) {
                    ++answer;
                }
            }
        }
    }

    cout << answer << '\n';
}
