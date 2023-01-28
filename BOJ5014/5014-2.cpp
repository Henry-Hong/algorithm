#include <iostream>
#include <vector>
#define INIT 0x7fffffff
using namespace std;

int visit[1000001]; // i번째 층에 오려면 몇번 시도해야 하는지 기록하는 배열.
int F, S, G, U, D;

void init() {
  for (int i = 1; i <= 1000000; i++)
    visit[i] = INIT;
}

int dfs(int floor, int count) {
  // 5014-1.cpp 에서 early return 되는 문제를 해결하고자, 변수를 활용했다.
  // 하지만 이 경우 dfs가 여러번 return 하게된다. 그래서 가장 마지막에 수행된
  // dfs가 answer를 덮어씌우게된다. 따라서 한번만 갱신하도록 코드를 수정하자.
  int result = -1;
  visit[floor] = count;
  if (floor == G)
    return count;
  int upper = floor + U;
  if (upper <= F && count + 1 < visit[upper])
    result = dfs(upper, count + 1);
  int lower = floor - D;
  if (lower >= 1 && count + 1 < visit[lower])
    result = dfs(lower, count + 1);
  return result;
}

int main() {

  init();

  cin >> F >> S >> G >> U >> D;

  int answer = dfs(S, 0);

  if (answer == -1)
    cout << "use the stairs";
  else
    cout << answer;

  return 0;
}