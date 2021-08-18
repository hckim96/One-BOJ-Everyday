#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAX_PEOPLE_NUM 200'000

int myFind(vector<int>& parent, int n1) {
    if (parent[n1] < 0) {
        return n1;
    }
    return parent[n1] = myFind(parent, parent[n1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int F;
        cin >> F;

        int seq = 0;
        map<string, int> m;
        vector<int> parent(MAX_PEOPLE_NUM + 1, -1);

        for (int i = 0; i < F; ++i) {
            string s1, s2;
            cin >> s1 >> s2;

            if (m.find(s1) == m.end()) {
                m[s1] = ++seq;
            }
            if (m.find(s2) == m.end()) {
                m[s2] = ++seq;
            }

            int p1 = myFind(parent, m[s1]);
            int p2 = myFind(parent, m[s2]);

            if (p1 != p2) {
                parent[p1] += parent[p2];
                parent[p2] = p1;
            }

            cout << abs(parent[p1]) << '\n';
        }
    }
}