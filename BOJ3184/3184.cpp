#include <iostream>
#include <vector>
#define MAX 251
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

char map[MAX][MAX];
int visit[MAX][MAX];

int row, col;
int total_sheep;
int total_wolf;
int cur_sheep;
int cur_wolf;

void dfs(int y, int x) {

  visit[y][x] = 1;
  if (map[y][x] == 'v')
    cur_wolf++;
  if (map[y][x] == 'o')
    cur_sheep++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (nx < 0 || ny < 0 || nx >= col || ny >= row)
      continue;

    if (visit[ny][nx] == 0 && map[y][x] != '#') {
      dfs(ny, nx);
    }
  }
}

int main() {

  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    cin >> map[i];
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cur_sheep = cur_wolf = 0;
      if (visit[i][j] == 0 && map[i][j] != '#')
        dfs(i, j);
      if (cur_sheep > cur_wolf)
        total_sheep += cur_sheep;
      else
        total_wolf += cur_wolf;
    }
  }

  cout << total_sheep << " " << total_wolf;

  return 0;
}