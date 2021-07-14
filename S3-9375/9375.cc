#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        map<string, int> m;

        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s >> s;

            auto it = m.find(s);
            
            if (it != m.end()) {
                ++(it -> second);
            } else {
                m[s] = 1;
            }
        }

        int answer = 1;
        for (auto e: m) {
            answer *= (e.second + 1);
        }
        cout << --answer << '\n';
    }
}