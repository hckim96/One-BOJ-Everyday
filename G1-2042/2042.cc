#include <iostream>

using namespace std;


#define N_MAX 1000000

int N, M, K;

// n 개
long long number[N_MAX] = {0};


// leaf = n 의 binary tree 노드 총 개수는 최대 2 ^ (ceil(lg N) + 1) - 1 개 : 올림 을 + 1 로 해서 4 * N - 1개 
// 4 * N_MAX - 1 개 인데 1 - index 니까 1개 더해
long long segmentTree[N_MAX * 4] = {0};

long long init(int nodeNum, int start, int end) {
    if (start == end) {
        // leaf node
        return segmentTree[nodeNum] = number[start];
    } else {
        int mid = (start + end) / 2;

        // left + right
        return segmentTree[nodeNum] = init(nodeNum * 2, start, mid) + init(nodeNum * 2 + 1, mid + 1, end);
    }
}

long long sum(int nodeNum, int nodeStart, int nodeEnd, int targetStart, int targetEnd) {

    if (nodeEnd < targetStart || targetEnd < nodeStart) {
        return 0;
    }
    if (targetStart <= nodeStart && nodeEnd <= targetEnd) {
        return segmentTree[nodeNum];
    }

    int mid = (nodeStart + nodeEnd) / 2;
    return sum(nodeNum * 2, nodeStart, mid, targetStart, targetEnd) + sum(nodeNum * 2 + 1, mid + 1, nodeEnd, targetStart, targetEnd);

}

void update(int nodeNum, int nodeStart, int nodeEnd, int targetIndex, long long diff) {
    if (targetIndex < nodeStart || nodeEnd < targetIndex) {
        return;
    }
 
    segmentTree[nodeNum] += diff;
    if (nodeStart != nodeEnd) {
        // not leaf node
        // should update it's child
        int mid = (nodeStart + nodeEnd) / 2;
        update(nodeNum * 2, nodeStart, mid, targetIndex, diff);
        update(nodeNum * 2 + 1, mid + 1, nodeEnd, targetIndex, diff);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }

    init(1, 0, N - 1);
    
    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        if (a == 1) {
            // modification
            // b번째 수를 c 로 (number[b - 1] = c)
            update(1, 0, N - 1, b - 1, c - number[b - 1]);
            number[b - 1] = c; // number 도 수정 해줘야 함
        } else {
            // sum
            // number[b- 1] 부터 number[c - 1] 까지의 합 두개 같을 수도 있음
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}