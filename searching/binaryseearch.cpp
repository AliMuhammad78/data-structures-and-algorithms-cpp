#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        // int mid = left + (right - left) / 2; // Calculate the middle index
int mid = (left + right)/2; 
        // Check if the key is present at the mid
        if (arr[mid] == key) {
            return mid; // Element found
        }
        // If the key is smaller than the mid element, search in the left half
        else if (key < arr[mid]) {
            return binarySearch(arr, left, mid - 1, key);
        }
        // If the key is greater than the mid element, search in the right half
        else {
            return binarySearch(arr, mid + 1, right, key);
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);    // Size of the array
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
