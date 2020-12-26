#include <iostream>

using namespace std;

int N, K;

// cnt >= K 를 만족하는 가장 작은 값 찾기
int binarySearch(int left, int right) {
    if (left > right) {
        return left;
    }

    int cnt = 0;
    int mid = (left + right) / 2;

    // i 행에서 mid 보다 작같/작 은 개수
    for (int i = 1; i <= N; i++) {
        cnt += min(mid / i, N);
    }

    if (cnt < K) {
        return binarySearch(mid + 1, right);
    } else {
        return binarySearch(left, mid - 1);
    }
}

int main() {
    cin >> N >> K;

    // 앞 K개가 모두 K 이하 임이 성립하므로
    // right 을 K로 줘도 됨
    cout << binarySearch(1, K) << "\n";
}