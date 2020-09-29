#include <iostream>
#include <functional>
#include <queue>
#include <list>

using namespace std;

// 최대 V 수 * w 최대 * 10
#define MAX 2000000

struct cmp{
    bool operator()(pair<int, int> t, pair<int, int> u){
        return t.second > u.second;
    }
};


int V, E, K;
int start;
// 노드번호, 최단 거리 
priority_queue <pair<int, int>, vector<pair<int,int> >, cmp> pq;

// nodenum, list

int main () {
    cin >> V >> E;
    cin >> start;

    int* answer = new int[V];
    bool* visited = new bool[V];
    vector <list <pair<int, int> >* > weight;
    weight.reserve(V);


    for (int i = 0; i < V; i++) {
        answer[i] = MAX;
        weight[i] = new list <pair<int, int> >;
        visited[i] = false;

        for (int j = 0; j < V; j++) {
            if (i == j) {
                weight[i] -> push_back(make_pair(i, 0));
            }
        }
    }
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        weight[u - 1] -> push_back(make_pair(v - 1, w));
    }
    pq.push(make_pair(start - 1, 0));

    while (!pq.empty()) {
        int nodeNum = pq.top().first;
        int pathLength = pq.top().second;
        pq.pop();
        if (visited[nodeNum]) {
            continue;
        }
        visited[nodeNum] = true;
        for (auto it = weight[nodeNum] -> begin(); it != weight[nodeNum] -> end(); it++) {
            if (answer[it -> first] > pathLength + it -> second) {
                answer[it -> first] = pathLength + it -> second;
                pq.push(make_pair(it -> first, answer[it -> first]));
                visited[it -> first] = false;

            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (answer[i] == MAX) {
            cout << "INF" << endl;
        } else {
            cout << answer[i] << endl;
        }
    }

}  
