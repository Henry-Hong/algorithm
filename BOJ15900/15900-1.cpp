#include <iostream>
#include <vector>
// 노드가 50만이기 때문에, adjacent list로 구현해야함. adjacent
// matrix로 구현을 하면 250,000,000개의 노드가 있기 때문에 배열이
// 모자람.
#define MAX 500001
using namespace std;

vector<int> v[MAX];
int depth[MAX];

void dfs(int start, int d) {
  depth[start] = d;
  for (int i = 0; i < v[start].size(); i++) {
    dfs(v[start][i], d + 1);
  }
}

int main() {

  int n, s, e, sum = 0;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    cin >> s >> e;
    v[s].push_back(e);
    // 트리의 개념을 떠올리다가, 트리는 한가지 노드로 갈 수 있는 길이 하나밖에
    // 없다는 사실을 떠올림. 길이 하나밖에 없으니까, 만약 2 1이 들어오면 2가
    // 부모, 1이 자식이라고 자연스럽게 생각함. 무작위로 인풋이 들어오기때문에,
    // 어떤 노드가 부모인지 알 수 없음. 즉 노드 번호가 작을수록 부모 노드라는
    // 보장이 없다는것임. 따라서 무방향으로 트리를 저장하자.
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 0) {
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