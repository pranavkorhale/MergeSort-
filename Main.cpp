#include <iostream>
using namespace std;

void Merge(int arr[], int left[], int right[], int len1, int len2);
void MergeSort(int arr[], int len);
void printArray(int arr[], int len);

void MergeSort(int arr[], int len) {
    if (len < 2) return;

    int mid = len / 2;
    int left[mid];
    int right[len - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }

    MergeSort(left, mid);
    MergeSort(right, len - mid);

    Merge(arr, left, right, mid, len - mid);
}

void Merge(int arr[], int left[], int right[], int len1, int len2) {
    int i = 0, j = 0, ind = 0;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[ind++] = left[i++];
        } else {
            arr[ind++] = right[j++];
        }
    }

    while (i < len1) {
        arr[ind++] = left[i++];
    }

    while (j < len2) {
        arr[ind++] = right[j++];
    }
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, len);
    printArray(arr, len);
    return 0;
}
