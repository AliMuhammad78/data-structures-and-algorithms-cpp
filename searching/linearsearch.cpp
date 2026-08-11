 #include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
 
    int arr[] = {12, 34, 87, 45, 67, 89, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the value to search: ";
    cin >> target;
 
    int result = linearSearch(arr, size, target);

 
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

