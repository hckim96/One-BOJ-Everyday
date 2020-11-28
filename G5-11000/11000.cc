#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define N_MAX 200000

// min heap
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > lecture;

// min heap
// end time
priority_queue<int, vector<int>, greater<int> > room;

int N, S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        lecture.push({S, T});
    }

    while (!lecture.empty()) {
        int topFirst, topSecond;
        topFirst = lecture.top().first;
        topSecond = lecture.top().second;
        lecture.pop();

        if (!room.empty() && room.top() <= topFirst) {
            room.pop();
        } 
        room.push(topSecond);
    }
    cout << room.size() << "\n";
}
