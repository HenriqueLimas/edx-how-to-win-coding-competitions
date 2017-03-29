#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int left, int right, int pivot) {
  while(left <= right) {
    while(arr[left] < arr[pivot]) {
      left++;
    }

    while(arr[right] > arr[pivot]) {
      right--;
    }

    if (left <= right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }

  return left;
}

void quicksort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = (left + right) / 2;

  int index = partition(arr, left, right, pivot);

  quicksort(arr, left, index - 1);
  quicksort(arr, index, right);
}

int main() {
  int arr[] = {4, 3, 2, 6, 7, 1};
  int len = 6;

  quicksort(arr, 0, len - 1);

  for(int i = 0; i < len; i++) {
    cout << " " << arr[i];
  }

  return 0;
}
