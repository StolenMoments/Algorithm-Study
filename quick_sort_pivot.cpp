#include <iostream>
using namespace std;

void quick(int *arr, int l, int r) {
	if (l < r) {
		// swap(arr[l], arr[idx]) idx : 피봇으로 설정할 인덱스
		// 시작이나 끝을 피벗으로 잡을 경우, 정렬된 배열을 정렬할 때 런타임 에러 발생
		// 중앙으로 놓으면 정렬된 배열을 정렬해도 잘 됨
		int pivot = l;
		int i = l;
		int j = r;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < r) i++;
			while (arr[j] > arr[pivot]) j--;
			if (i < j) swap(arr[i], arr[j]);
		}
		
		swap(arr[pivot], arr[j]);
		quick(arr, l, j - 1);
		quick(arr, j + 1, r);
	}
}

int main() {
	int arr[10] = { 3,4,1,7,4,5,10,7,9,1 };
	quick(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 1,1,3,4,4,5,6,7,7,9,10
}
