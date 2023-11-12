#include <iostream>
#include<Windows.h>

// Бінарний код
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    
    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    
    if (largest != rootIndex) {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size) {
    
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    
    for (int i = size - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (arr[mid] == target) {
            return mid;
        }

        
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    
    return -1;
}

int main() {
    system("chcp 1251");
    system("cls");
    int unsortedArray[] = { 5, 3, 8, 2, 1, 4, 7, 6, 10, 9 };
    int size = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    
    heapSort(unsortedArray, size);

    int target = 6;

    int result = binarySearch(unsortedArray, size, target);

    if (result != -1) {
        std::cout << "Елемент " << target << " знайдено на позиції " << result << std::endl;
    }
    else {
        std::cout << "Елемент " << target << " не знайдено в масиві" << std::endl;
    }

    return 0;
}
