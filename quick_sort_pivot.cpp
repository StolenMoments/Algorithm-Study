#include <iostream>
using namespace std;

void quick(int *arr, int l, int r) {
	if (l < r) {
		//swap(arr[l], arr[idx]) idx : 피봇으로 설정할 인덱스
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
