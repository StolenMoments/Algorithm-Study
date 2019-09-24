#include <iostream>
#define MAX_SIZE 1000000
using namespace std;


int tmp[MAX_SIZE]; // 임시 배열

void msort(int* arr, int l, int r) {
	if (l == r) return;
	if (r - l == 1) {
		if (arr[r] < arr[l]) swap(arr[r], arr[l]);
		return;
	}
	
	int idx = 0;
	int left = l;
	int mid = (l + r) / 2;
	int right = mid + 1;

	msort(arr, l, mid);
	msort(arr, right, r);


	while (left <= mid && right <= r) {
		if (arr[left] < arr[right]) tmp[idx++] = arr[left++];
		else tmp[idx++] = arr[right++];
	}
	

	while (left <= mid) tmp[idx++] = arr[left++];
	while (right <= r) tmp[idx++] = arr[right++];

	idx = 0;
	for (int i = l; i <= r; i++) arr[i] = tmp[idx++];
}

int main(){
	int arr[10] = { 3,4,1,7,4,5,10,7,9,1 };
	msort(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 1,1,3,4,4,5,6,7,7,9,10
}
