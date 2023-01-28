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
  visit[floor] = count;
  if (floor == G)
    return count;
  int upper = floor + U;
  // 이런식이면 early return이 되어버려서 아래층으로 가는 코드가 실행조차
  // 되지않는다. 바보! 33% 에서 실패!
  if (upper <= F && count + 1 < visit[upper])
    return dfs(upper, count + 1);
  int lower = floor - D;
  if (lower >= 1 && count + 1 < visit[lower])
    return dfs(lower, count + 1);
  return -1;
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