#include <iostream>
#include <utility>
#include <vector>
#define HOUSE 1
#define CHICKEN 2
using namespace std;

typedef pair<int, int> pii;

int N, M;
int houses_size;
int chickens_size;
int map[51][51];
int pick[13];
int answer = 0x7fffffff;
vector<pii> chickens(1);
vector<pii> houses(1);

int abs(int a, int b) { return a - b > 0 ? a - b : b - a; }

int getDistance(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void combination(int depth, int n, int k, int start) {

  if (depth == k) {
    int total_dist = 0;
    for (int i = 1; i < houses.size(); i++) {
      int nearest = 0x7fffffff;
      pii house = houses[i];
      for (int j = 0; j < k; j++) {
        pii chicken = chickens[pick[j]];
        int dist = getDistance(house, chicken);
        if (dist < nearest)
          nearest = dist;
      }
      total_dist += nearest;
    }
    if (total_dist < answer)
      answer = total_dist;
  }

  for (int i = start; i <= n; i++) {
    pick[depth] = i;
    combination(depth + 1, n, k, i + 1);
  }
}

int main() {

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      if (map[i][j] == HOUSE) {
        houses_size++;
        houses.push_back(make_pair(i, j));
      } else if (map[i][j] == CHICKEN) {
        chickens_size++;
        chickens.push_back(make_pair(i, j));
      }
    }
  }

  int n = chickens_size;
  int k = M;
  int s = 1;

  combination(0, n, k, s);

  cout << answer;

  return 0;
}