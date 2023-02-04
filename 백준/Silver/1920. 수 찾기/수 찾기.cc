#include <stdio.h>
#include <stdlib.h>

int arr[100001];

int biSearch(int s, int e, int cmp) {
	
	if (s > e) return 0;

	int result = 0;
	int mid = (s + e) / 2;

	if (arr[mid] > cmp) {
		result = biSearch(s, mid - 1, cmp);
	}
	else if (arr[mid] < cmp) {
		result = biSearch(mid + 1, e, cmp);
	}
	else { // 같음
		result = 1;
	}

	return result;
}

int compare(const void* a, const void* b) {
	return *(int*)a > *(int*)b;
}

int main() {

	int n, m, cmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	//정렬
	qsort(arr, n, sizeof(int), compare);
	   	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {

		scanf("%d", &cmp);

		if (biSearch(0,n-1,cmp)) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}