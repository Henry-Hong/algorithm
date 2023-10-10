#include <stdio.h>
#include <queue>
using namespace std;

typedef struct pos {
	int x; int y;
} pos;
int map[100][100];
int garo, sero, k, ans=0;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

void bfs(int y, int x) {

	queue<pos> q;
	
	q.push(pos{ x, y });
	map[y][x] = 0;

	while (!q.empty()) {
		
		pos t;
		t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = t.x + dx[i];
			int cy = t.y + dy[i];
			if (cx >= 0 && cx < garo && cy >= 0 && cy < sero && map[cy][cx] == 1) {
				q.push(pos{ cx, cy });
				map[cy][cx] = 0;
			}
		}
	}
}

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {

		scanf("%d %d %d", &garo, &sero, &k);
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		for (int i = 0; i < sero; i++) {
			for (int j = 0; j < garo; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		}
		
		printf("%d\n", ans);
		ans = 0;
	}

	return 0;
}