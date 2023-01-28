#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

vector<int> v[MAX];
int depth[MAX];
int visit[MAX];

void dfs(int start, int d) {
  depth[start] = d;
  visit[start] = 1;
  for (int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if (visit[next] == 0)
      dfs(next, d + 1);
  }
}

int main() {

  int n, s, e, sum = 0;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    cin >> s >> e;
    v[s].push_back(e);
    v[e].push_back(s);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 1) {
      sum += depth[i];
    }
  }

  if (sum % 2 == 0) {
    printf("No");
  } else {
    printf("Yes");
  }

  return 0;
}