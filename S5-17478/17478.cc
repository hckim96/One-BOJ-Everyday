#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  cin >> N;

  auto p = [&](int n) {
    n *= 4;
    while (n--) cout << '_';
  };
  function<void(int)> f = [&](int n) {

    if (n == N) {
      p(n);
      cout << "\"재귀함수가 뭔가요?\"\n";
      p(n);
      cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
      p(n);
      cout << "라고 답변하였지.\n";
      return;
    }
    p(n);
    cout << "\"재귀함수가 뭔가요?\"\n";
    p(n);
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    p(n);
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    p(n);
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    f(n + 1);
    p(n);
    cout << "라고 답변하였지.\n";
  };
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  f(0);
}