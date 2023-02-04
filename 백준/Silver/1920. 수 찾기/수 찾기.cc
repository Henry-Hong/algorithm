#include <algorithm>
#include <iostream>
using namespace std;

int N, M, x;
int arr[100001];

int binarySearch(int x) {

  int left = 0, right = N - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (x == arr[mid])
      return 1;
    else if (x < arr[mid])
      right = mid - 1;
    else if (x > arr[mid])
      left = mid + 1;
    else
      cout << "not reachable";
  }
  return 0;
}

int main() {

  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  sort(arr, arr + N);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> x;
    cout << binarySearch(x) << "\n";
  }

  return 0;
}