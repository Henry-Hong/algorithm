#include <stdio.h>
#define ll long long

int arr[2000000];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int max = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	ll s = 0;
	ll e = max;
	ll ans = 0;
	ll mid = 0;

	while (s <= e) {

		mid = (s + e) / 2;

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			ll t = arr[i] - mid;
			if (t > 0) sum += t;
		}

		if (sum == m) {
			ans = mid;
			break;
		}
		else if (sum < m) {
			e = mid - 1;
		}
		else {
			ans = mid;
			s = mid + 1;
		}
	}

	printf("%lld", ans);

	return 0;
}