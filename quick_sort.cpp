#include <iostream>
using namespace std;

void quick(int* arr, int l, int r) {
	if (l < r) {
		int pivot = arr[r]; // 끝을 피봇으로 설정
		int i = l - 1;

		for (int j = l; j < r; j++)
		if (arr[j] <= pivot) 	swap(arr[++i], arr[j]); // 피봇보다 작은 값들을 왼쪽으로 몰아 넣는다.
		swap(arr[i + 1], arr[r]);

		// 나머지 부분 정렬
		quick(arr, l, i);
		quick(arr, i + 2, r);
	}
}

int main() {
	int arr[10] = { 3,4,1,7,4,5,10,7,9,1 };
	quick(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 1,1,3,4,4,5,6,7,7,9,10
}
