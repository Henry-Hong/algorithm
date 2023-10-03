#include <stdio.h>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
};

int garo, sero;
char map[100][100];
int dst[100][100];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int maxv = -1;

void bfs(int y, int x) {

	queue<pos> q;

	int chk[100][100] = { 0 };
	chk[y][x] = 1;
	dst[y][x] = 0;

	q.push({ x,y });

	while (!q.empty()) {

		pos t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = t.x + dx[i];
			int cy = t.y + dy[i];
			if (cx >= 0 && cy >= 0 && cx < garo && cy < sero) {
				if (map[cy][cx] == 'L' && chk[cy][cx] == 0) {
					q.push({ cx,cy });
					chk[cy][cx] = 1;
					dst[cy][cx] = dst[t.y][t.x] + 1;
					if (maxv < dst[cy][cx]) maxv = dst[cy][cx];
				}
			}
		}

	}
}

int main() {

	scanf("%d %d", &sero, &garo);

	for (int i = 0; i < sero; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			if (map[i][j] == 'L') {
				bfs(i,j);
			}
		}
	}
	
	printf("%d", maxv);

	return 0;
}