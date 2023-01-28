#include <iostream>
#include <vector>
#define INIT 0x7fffffff
using namespace std;

int answer = -1;
int visit[1000001]; // i번째 층에 오려면 몇번 시도해야 하는지 기록하는 배열.
int F, S, G, U, D;

void init() {
  for (int i = 1; i <= 1000000; i++)
    visit[i] = INIT;
}

void dfs(int floor, int count) {
  visit[floor] = count;
  if (floor == G) {
    answer = count; // 정답이 결정되면 한번만 갱신하도록 코드를 수정.
    return;
  }
  int upper = floor + U;
  if (upper <= F && count + 1 < visit[upper])
    dfs(upper, count + 1);
  int lower = floor - D;
  if (lower >= 1 && count + 1 < visit[lower])
    dfs(lower, count + 1);
}

int main() {

  init();

  cin >> F >> S >> G >> U >> D;

  dfs(S, 0);

  if (answer == -1)
    cout << "use the stairs";
  else
    cout << answer;

  return 0;
}