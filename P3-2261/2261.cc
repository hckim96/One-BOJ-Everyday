#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

// [s, e]
int f(vector<pair<int, int> >& point, int s, int e) {
    if (s == e) {
        return INF;
    }

    if (s + 1 == e) {
        int dy = point[e].second - point[s].second;
        int dx = point[e].first - point[s].first;
        return dx * dx + dy * dy;
    }

    int mid = (s + e) / 2;
    
    int dLeft = f(point, s, mid);
    int dRight = f(point, mid + 1, e);

    int d = min(dLeft, dRight);

    if (d == 0) {
        return 0;
    }

    double lineX = (point[mid].first + point[mid + 1].first) / 2;

    auto it1 = point.begin() + mid;
    while (it1 != point.begin() + s && (lineX - it1 -> first) * (lineX - it1 -> first) < d) {
        it1--;
    }

    auto it2 = point.begin() + mid + 1;
    while (it2 != point.begin() + e + 1 && (it2 -> first - lineX) * (it2 -> first - lineX) < d) {
        it2++;
    }

    vector<pair<int, int> > tmp(it1, it2);

    sort(tmp.begin(), tmp.end(), cmp);

    int tmpMin = INF;

    for (int i = 0; i < tmp.size(); ++i) {
        for (int j = i + 1; j < min(i + 5, (int)tmp.size()); ++j) {
            if ((lineX - tmp[i].first) * (lineX - tmp[j].first) > 0) {
                continue;
            }
            
            int dx = tmp[i].first - tmp[j].first;
            int dy = tmp[i].second - tmp[j].second;

            int tmpD = dx * dx + dy * dy;
            if (tmpMin > tmpD) {
                tmpMin = tmpD;
                if (tmpMin == 0) {
                    return 0;
                }
            }
        }
    }

    return min(tmpMin, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > point(N);

    for (auto &[f, s]: point) {
        cin >> f >> s;
    }

    sort(point.begin(), point.end());

    cout << f(point, 0, N - 1) << '\n';
}
