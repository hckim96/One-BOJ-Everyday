#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
cube[idx] = color
                U
             0  1  2
             3  4  5
             6  7  8
   9 10 11 |12 13 14| 15 16 17| 18 19 20 
L 21 22 23 |24 25 26| 27 28 29| 30 31 32 B
  33 34 35 |36 37 38| 39 40 41| 42 43 44
            45 46 47
            48 49 50
            51 52 53
                D
*/

string initialStateOfCube = "wwwwwwwwwgggrrrbbbooogggrrrbbbooogggrrrbbboooyyyyyyyyy";
enum FACE {UPPER, DOWN, FRONT, BACK, LEFT, RIGHT, FACE_SIZE};
map<char, FACE> faceCharToEnumMap = {
    {'U', UPPER},
    {'D', DOWN},
    {'F', FRONT},
    {'B', BACK},
    {'L', LEFT},
    {'R', RIGHT}
};

// 뒤로 2칸, 3칸 씩 미뤄야 시계방향 회전
vector<vector<vector<int> > > rotatePos = {
    {
        {0, 1, 2, 5, 8, 7, 6, 3},
        {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9},
    },
    {
        {45, 46, 47, 50, 53, 52, 51, 48},
        {36, 37, 38, 39, 40, 41, 42, 43, 44, 33, 34, 35},
    },
    {
        {12, 13, 14, 26, 38, 37, 36, 24},
        {6, 7, 8, 15, 27, 39, 47, 46, 45, 35, 23, 11},
    },
    {
        {18, 19, 20, 32, 44, 43, 42, 30},
        {2, 1, 0, 9, 21, 33, 51, 52, 53, 41, 29, 17},
    },
    {
        {9, 10, 11, 23, 35, 34, 33, 21},
        {0, 3, 6, 12, 24, 36, 45, 48, 51, 44, 32, 20},
    },
    {
        {15, 16, 17, 29, 41, 40, 39, 27},
        {8, 5, 2, 18, 30, 42, 53, 50, 47, 38, 26, 14},
    },
};

void rotate90DegreeCW(string& cube, FACE face, int cnt) {
    for (auto layer: rotatePos[face]) {
        string tmp;

        int pushCnt = layer.size() / 4;
        pushCnt *= cnt;

        for (auto p: layer) {
            tmp += cube[p];
        }

        string ttmp = tmp.substr(0, pushCnt);
        for (int i = tmp.size() - 1; i >= 0; --i) {
            if (i < pushCnt) {
                tmp[(i + pushCnt) % layer.size()] = ttmp[i];
            } else {
                tmp[(i + pushCnt) % layer.size()] = tmp[i];
            }
        }

        int idx = 0;
        for (auto p: layer) {
            cube[p] = tmp[idx++]; 
        }
    }
}

void rotate(string& cube, char face, char direction) {
    int cnt = direction == '+' ? 1 : 3;
    rotate90DegreeCW(cube, faceCharToEnumMap[face], cnt);
}

void printUpperFace(string& cube) {
    for (int i = 0; i < 9; ++i) {
        cout << cube[i];
        if (i % 3 == 2) {
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string cube(initialStateOfCube);

        while (N--) {
            string s;
            cin >> s;
            rotate(cube, s[0], s[1]);
        }
        printUpperFace(cube);
    }
}