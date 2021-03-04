#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> last;
    
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        auto it = lower_bound(last.begin(), last.end(), tmp);
        if (it == last.end()) {
            last.push_back(tmp);
        } else {
            *it = tmp;
        }
    }
    
    cout << last.size() << '\n';
}