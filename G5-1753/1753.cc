#include <iostream>
#include <functional>
#include <queue>

using namespace std;


struct cmp{
    bool operator()(pair<int, int> t, pair<int, int> u){
        return t.second > u.second;
    }
};


int V, E, K;

priority_queue <pair<int, int>, vector<pair<int,int> >, cmp> pq;




int main () {
             

    pq.push(make_pair(1, 2));
    pq.push(make_pair(2,1 ));
    pq.push(make_pair(3, 5));
    pq.push(make_pair(0, 4));

    while (!pq.empty()) {
        int first = pq.top().first;
        int second = pq.top().second;
        pq.pop();
        cout << first << second << endl;
    }
}
