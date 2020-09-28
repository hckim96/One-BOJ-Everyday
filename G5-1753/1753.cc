#include <iostream>
#include <functional>
#include <queue>

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


int main () {
    cin >> V >> E;
    cin >> start;

    int** weight = new int*[V];
    for (int i = 0; i < V; i++) {
        weight[i] = new int[V];
    }
    int* answer = new int[V];


    for (int i = 0; i < V; i++) {
        answer[i] = MAX;
        for (int j = 0; j < V; j++) {
            if (i == j) {
                weight[i][j] = 0;
            } else {
                weight[i][j] = MAX;
            }
        }
    }
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        weight[u - 1][v - 1] = w;
    }
    pq.push(make_pair(start - 1, weight[start - 1][start - 1]));

    while (!pq.empty()) {
        int nodeNum = pq.top().first;
        int pathLength = pq.top().second;
        pq.pop();

        for (int i = 0; i < V; i++) {
            if (weight[nodeNum][i] != MAX) {
                if (answer[i] > pathLength + weight[nodeNum][i]) {
                    answer[i] = pathLength + weight[nodeNum][i];
                    pq.push(make_pair(i, answer[i]));
                }
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
    for (int i = 0; i < V; i++) {
        delete[] weight[i];
    }
    delete[] weight;

    delete[] answer;
}  
