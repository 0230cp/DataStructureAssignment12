#include <iostream>
#include <stdlib.h>
using namespace std;

void BubbleSort(int list[])
{
	int temp;

	for (int i = 0; i < sizeof(list); i++)
	{
		for (int j = 0; j < sizeof(list); j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
		for (int i = 0; i <= sizeof(list); i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}

void insertionSort(int list[]) {
	int j,k, key;

	for (int i = 0; i <= sizeof(list); i++) {
		key = list[i];

		for (j = i - 1; j >= 0; j--) {
			if (list[j] > key) {
				list[j + 1] = list[j];
				for (int i = 0; i <= sizeof(list); i++) {
					cout << list[i] << " ";
				}
				cout << endl;
			}
			else {
				break;
			}
		}
		list[j + 1] = key;
		
	}
	for (int i = 0; i <= sizeof(list); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

void quickSort(int list[], int start, int end) {


	if (start >= end) {
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	for (int i = 0; i < 9; i++) {
		cout << list[i] << " ";
	}
	cout << endl;

	while (i <= j) {
		while (list[i] <= list[pivot]) {
			i++;
		}
		while (list[j] >= list[pivot] && j > start) {
			j--;
		}
		if (i > j) {
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else {
			temp = list[j];
			list[j] = list[i];
			list[i] = temp;
		}

		quickSort(list, start, j - 1);
		quickSort(list, j + 1, end);
	}
}

void merge(int list[], int start, int mid, int end) {
	int sorted[5];

	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (list[i] <= list[j]) {
			sorted[k] = list[i];
			i++;
		}
		else {
			sorted[k] = list[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = list[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = list[t];
			k++;
		}
	}

	// 정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		list[t] = sorted[t];
	}
}

void mergeSort(int list[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(list, start, mid); 
		mergeSort(list, mid + 1, end);
		merge(list, start, mid, end);
	}
	for (int i = 0; i < 5; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[5] = { 3,5 , 6 ,9 , 4 };
	cout << "BubbleSort: ";
	BubbleSort(arr);

	int arr1[5] = { 6,5,7,4,3 };
	cout << "insertionSort: ";
	insertionSort(arr1);

	int arr3[9] = {5,3,8,4,9,1,6,2,7 };
	cout << "quickSort: ";
	quickSort(arr3,0,8);
	cout << endl;

	int arr4[5] = { 6,5,12,10,9 };
	cout << "mergeSort: ";
	mergeSort(arr4, 0, 4);
}