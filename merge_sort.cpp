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
	int right = (l + r) / 2 + 1;

	msort(arr, l, right - 1);
	msort(arr, right, r);


	while (left <= (l + r) / 2 && right <= r) {
		if (arr4[left] < arr4[right]) tmp[idx++] = arr4[left++];
		else tmp[idx++] = arr4[right++];
	}
	

	while (left <= (l + r) / 2) tmp[idx++] = arr4[left++];
	while (right <= r) tmp[idx++] = arr4[right++];

	idx = 0;
	for (int i = l; i <= r; i++) arr4[i] = tmp[idx++];
}

int main(){
	int arr[10] = { 3,4,1,7,4,5,10,7,9,1 };
	msort(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 1,1,3,4,4,5,6,7,7,9,10
}
