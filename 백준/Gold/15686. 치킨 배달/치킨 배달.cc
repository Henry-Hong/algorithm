#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
struct pos {
	int x;
	int y;
};

int N, M, menus=0;

vector<pos> homes;
vector<pos> chickens; //순열 data들.

int ans = 1000000000;
int pick[100];

void display(int sum) {
	for (int i = 0; i < M; i++) {
		printf("%d ", pick[i]);
	}
	printf("일때, \n");

	printf("거리의 합 : %d\n\n", sum);
}

void comb(int idx, int n, int m, int aft) {

	if (idx == m) {

		int sum = 0;
		for (int i = 0; i < homes.size(); i++) {
			int hx = homes[i].x;
			int hy = homes[i].y;
			int min = 1000000000;
			for (int k = 0; k < m; k++) {
				int cx = chickens[pick[k]].x;
				int cy = chickens[pick[k]].y;

				int dist = abs(cx - hx) + abs(cy - hy);
				
				if (dist < min) min = dist;
			}

			sum += min;
		}

		if (sum < ans) ans = sum;
		return;
	}

	for (int i = aft; i < n; i++) {
		pick[idx] = i;
		comb(idx + 1, n, m, i + 1);
	}

}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			scanf("%d", &t);
			if (t == 1) {
				homes.push_back({ i,j });
			}
			else if (t == 2) {
				chickens.push_back({ i,j });
				menus++;
			}
		}
	}

	comb(0, menus, M, 0);

	printf("%d", ans);

	return 0;
}