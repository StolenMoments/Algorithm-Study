#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int arr1[800000];
int arr2[800000];
int arr3[800000];
int arr4[800000];
int arr5[800000];
int arr6[800000];
int tmp[800000];


void quick(int* arr, int l, int r) {
	if (l < r) {
		// swap(arr[l], arr[idx]) idx : 피봇으로 설정할 인덱스
		// 시작이나 끝을 피벗으로 잡을 경우, 정렬된 배열을 정렬할 때 런타임 에러 발생
		// 중앙으로 놓으면 정렬된 배열을 정렬해도 잘 됨
		int pivot = l;
		int i = l;
		int j = r;
		int tmp;
		while (i < j) {
			while (arr[i] <= arr[pivot] && i < r) i++;
			while (arr[j] > arr[pivot]) j--;
			if (i < j) {
				// swap 함수가 생각보다 시간을 좀 잡아먹더라..
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		tmp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = tmp;

		quick(arr, l, j - 1);
		quick(arr, j + 1, r);
	}
}

void quick2(int* arr, int l, int r) {
	if (l < r) {
		int tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;

		int pivot = l;
		int i = l;
		int j = r;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < r) i++;
			while (arr[j] > arr[pivot]) j--;
			if (i < j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		tmp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = tmp;
		quick2(arr, l, j - 1);
		quick2(arr, j + 1, r);
	}
}

void quick3(int* arr, int l, int r) {
	if (l < r) {
		int tmp = arr[(l + r) / 2];
		arr[(l + r) / 2] = arr[l];
		arr[l] = tmp;

		int pivot = l;
		int i = l;
		int j = r;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < r) i++;
			while (arr[j] > arr[pivot]) j--;
			if (i < j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		tmp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = tmp;
		quick3(arr, l, j - 1);
		quick3(arr, j + 1, r);
	}
}

void msort(int l, int r) {
	if (l == r) return;
	if (r - l == 1) {
		if (arr4[r] < arr4[l]) {
			int tmp = arr4[l];
			arr4[l] = arr4[r];
			arr4[r] = tmp;
		}
		return;
	}
	
	int idx = 0;
	int left = l;
	int right = (l + r) / 2 + 1;

	msort(l, right - 1);
	msort(right, r);


	while (left <= (l + r) / 2 && right <= r) {
		if (arr4[left] < arr4[right]) tmp[idx++] = arr4[left++];
		else tmp[idx++] = arr4[right++];
	}
	

	while (left <= (l + r) / 2) tmp[idx++] = arr4[left++];
	while (right <= r) tmp[idx++] = arr4[right++];

	idx = 0;
	for (int i = l; i <= r; i++) arr4[i] = tmp[idx++];
}

int cmp(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if (x < y) return -1;
	return x > y;
}

int main() {
	for (int i = 0; i < 800000; i++) arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] = rand() + rand() * 10 + rand() * 100;

	chrono::system_clock::time_point start = chrono::system_clock::now();
	quick(arr1, 0, 799999);
	chrono::duration<double> sec = chrono::system_clock::now() - start;
	cout << "시작 피벗 : " << sec.count() << endl;

	start = chrono::system_clock::now();
	quick2(arr2, 0, 799999);
	sec = chrono::system_clock::now() - start;
	cout << "끝 피벗 : " << sec.count() << endl;

	start = chrono::system_clock::now();
	quick3(arr3, 0, 799999);
	sec = chrono::system_clock::now() - start;
	cout << "중앙 피벗 : " << sec.count() << endl;
	
	start = chrono::system_clock::now();
	msort(0, 799999);
	sec = chrono::system_clock::now() - start;
	cout << "머지 소트 : " << sec.count() << endl;

	start = chrono::system_clock::now();
	sort(arr5, arr5 + 800000);
	sec = chrono::system_clock::now() - start;
	cout << "STL sort : " << sec.count() << endl;

	start = chrono::system_clock::now();
	qsort(arr6, sizeof(arr6) / sizeof(int), sizeof(int), cmp);
	sec = chrono::system_clock::now() - start;
	cout << "qsort : " << sec.count() << endl;
}
