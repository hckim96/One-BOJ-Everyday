#include <iostream>
#include <algorithm>

using namespace std;


#define H_MAX 500000

// N even
int N, H;

int floor[H_MAX / 2] = {0};
int ceiling[H_MAX / 2] = {0};

int sectionCnt = 0;
int destroyNum = 987654321;
int shouldDestroy[H_MAX];

int main() {

    fill_n(&shouldDestroy[0], H_MAX, 987654321);

    cin >> N >> H;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            cin >> floor[i / 2];
        } else {
            cin >> ceiling[i / 2];
        }
    }

    sort(floor, floor + (N / 2));
    sort(ceiling, ceiling + (N / 2));

    for (int section = 0; section < H; section++) {
        int floorDestroyNum = (&floor[0] + (N / 2)) - upper_bound(floor, floor + (N / 2), section);
        int ceilingDestroyNum = (&ceiling[0] + (N / 2)) - lower_bound(ceiling, ceiling + (N / 2), H - section);
        shouldDestroy[section] = floorDestroyNum + ceilingDestroyNum;


        if (destroyNum > shouldDestroy[section]) {
            destroyNum = shouldDestroy[section];
            sectionCnt = 1;
        } else if (destroyNum == shouldDestroy[section]) {
            sectionCnt++;
        }
    }   

    cout << destroyNum << "\n" << sectionCnt << "\n";
}