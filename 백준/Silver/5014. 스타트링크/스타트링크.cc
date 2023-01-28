#include <stdio.h>
#include <queue>
#define BIG 2100000000
using namespace std;

int F, S, G, U, D;
int ans = 0;
int mv[2] = {};
int dst[1000001];
int flag = 0;

void init() {
	for (int i = 0; i <= F; i++) {
		dst[i] = BIG;
	}
}

void bfs(int start) {

	init();

	queue<int> q;

	q.push(start);
	dst[start] = 0;

	while (!q.empty()) {

		int t = q.front(); q.pop();
		if (t == G) {
			flag = 1;
			ans = dst[t];
			return;
		}

		for (int i = 0; i < 2; i++) {
			int nxt = mv[i] + t;
			if (nxt > 0 && nxt <= F && dst[nxt] > dst[t] + 1) {
				dst[nxt] = dst[t] + 1;
				q.push(nxt);
			}
		}
	}
}

int main() {

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	mv[0] = U;
	mv[1] = -D;

	bfs(S);

	if (flag == 1)	printf("%d", ans);
	else printf("use the stairs");

	return 0;
}