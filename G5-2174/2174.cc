#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define COORDINATE_MAX 100
#define OPERATION_MAX 100
#define ROBOT_MAX 100


enum ROBOT_DIRECTION {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

int A, B, N, M;

// 북 동 서 남 순서인데 r 방향이 y 방향이랑 반대라서 반대로 해줌
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

// robotIdx
int map[COORDINATE_MAX + 1][COORDINATE_MAX + 1] = {0};

vector<tuple<int, int, ROBOT_DIRECTION> > robot;
vector<tuple<int, char, int> > operation;

bool shouldPrintOK = true; 
bool executeOperation(tuple<int, char, int>& op) {
    int robotIdx, NumOfOperation;
    char operation;

    tie(robotIdx, operation, NumOfOperation) = op;
    int r, c;
    ROBOT_DIRECTION dir;
    tie(r,c, dir) = robot[robotIdx];

    if (operation == 'F') {
        for (int i = 0; i < NumOfOperation; i++) {

            int nextR, nextC;
            
            nextR = r + dr[dir];
            nextC = c + dc[dir];

            if (nextR < 0 || nextR >= B || nextC < 0 || nextC >= A) {
                cout << "Robot "<< robotIdx + 1<< " crashes into the wall" << "\n";
                return false;
            }
            if (map[nextR][nextC] > 0) {
                cout << "Robot " << robotIdx + 1 << " crashes into robot "<< map[nextR][nextC] << "\n";
                return false;
            }

            map[r][c] = 0;
            r = nextR;
            c = nextC;
            map[r][c] = robotIdx + 1;
            get<0>(robot[robotIdx]) = r;
            get<1>(robot[robotIdx]) = c;
        }
        return true;
    } else if (operation == 'L') {
        switch (NumOfOperation % 4) {
            case 0:
                break;
            case 1:
                dir = (ROBOT_DIRECTION)(((int)dir + 3) % 4);
                break;
            case 2:
                dir = (ROBOT_DIRECTION)(((int)dir + 2) % 4);
                break;
            case 3:
                dir = (ROBOT_DIRECTION)(((int)dir + 1) % 4);
                break;
        }
        get<2>(robot[robotIdx]) = dir;
        return true;
    } else if (operation == 'R') {
        switch (NumOfOperation % 4) {
            case 0:
                break;
            case 1:
                dir = (ROBOT_DIRECTION)(((int)dir + 1) % 4);
                break;
            case 2:
                dir = (ROBOT_DIRECTION)(((int)dir + 2) % 4);
                break;
            case 3:
                dir = (ROBOT_DIRECTION)(((int)dir + 3) % 4);
                break;
        }
        get<2>(robot[robotIdx]) = dir;
        return true;
    }
}

int main() {
    cin >> A >> B;
    cin >> N >> M;
    
    robot.reserve(N * sizeof(tuple<int, int, ROBOT_DIRECTION>));
    operation.reserve(M * sizeof(tuple<int, char, int>));
    for (int i = 0; i < N; i++) {
        int tmpX, tmpY;
        char tmpDir;
        cin >> tmpX >> tmpY >> tmpDir;
        ROBOT_DIRECTION tmpRobotDir;

        switch (tmpDir)
        {
        case 'N':
            tmpRobotDir = NORTH;
            break;
        case 'E':
            tmpRobotDir = EAST;
            break;
        case 'S':
            tmpRobotDir = SOUTH;
            break;
        case 'W':
            tmpRobotDir = WEST;
            break;
        
        default:
            break;
        }
        robot.push_back({tmpY - 1, tmpX - 1, tmpRobotDir});
        map[tmpY - 1][tmpX - 1] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        int tmpRobot, tmpNum;
        char tmpOperation;
        cin >> tmpRobot >> tmpOperation >> tmpNum;

        operation.push_back({tmpRobot - 1, tmpOperation, tmpNum});
    }

    for (int i = 0; i < M; i++) {
        if (!executeOperation(operation[i])) {
            return 0;
        }
    }

    cout << "OK" << "\n";
    return 0;

}